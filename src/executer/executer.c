/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 02:28:30 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Execute a non-builtin command.

@param var    The t_var structure containing the command.
@return             The exit status of the command execution.
*/
static int	exec_command_not_builtin(
	t_var *var)
{
	char	**env;

	var->command_array = exec_build_cmd(var->cmd_current);
	if (!var->command_array[0])
		return (EXIT_FAILURE);
	env = exec_build_env(var->l_env);
	if (access(var->command_array[0], X_OK) == 0)
		execve(var->command_array[0], var->command_array, env);
	else
	{
		if (execute_command_with_path(var, env) == 127)
			return (127);
	}
	free_2d_char(env);
	return (EXIT_SUCCESS);
}

/*
@brief Execute command redirections.

@param var                The t_var structure containing the command.
@param index              The index of the command in the pipeline.
@param fd_parent     The file descriptor of the parent process.
@param fd_child       A pointer to the file descriptor of the child process.
@return             The exit status of the redirection execution.
*/
static int	exec_redirections(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_child)
{
	int	result_redirections_in;
	int	result_redirections_out;

	close(fd_child[READ_END]);
	result_redirections_in = redir_in_handle(var);
	if (result_redirections_in == EXIT_CODE)
		return (EXIT_CODE);
	if (!(result_redirections_in == HERE_DOC
			|| result_redirections_in == REDIR_IN))
		exec_redirect_fd(fd_parent, STDIN_FILENO);
	result_redirections_out = redir_out_handle(var);
	if (result_redirections_out == EXIT_CODE)
		return (EXIT_CODE);
	if (!(result_redirections_out == REDIR_OUT
			|| result_redirections_out == APPEND)
		&& index < var->n_cmds - 1)
		exec_redirect_fd(fd_child[WRITE_END], STDOUT_FILENO);
	close(fd_parent);
	close(fd_child[WRITE_END]);
	g_process.return_code = 0;
	return (EXIT_SUCCESS);
}

/*
@brief Execute the parent process routine.

@param var                The t_var structure containing the command.
@param index              The index of the command in the pipeline.
@param fd_to_child    A pointer to the file descriptor to the child process.
@param pid                 The process ID of the child process.
*/
static void	exec_parent_routine(
	t_var *var,
	int index,
	int *fd_to_child,
	pid_t pid)
{
	close(fd_to_child[WRITE_END]);
	if (index < var->n_cmds - 1)
	{
		reset_cmd_ptrs(var, get_cmd_start(var));
		executer(var, ++index, fd_to_child[READ_END]);
	}
	close(fd_to_child[READ_END]);
	g_process.pid = pid;
	waitpid(pid, &g_process.return_code, 0);
	g_process.return_code = WEXITSTATUS(g_process.return_code);
}

/*
@brief Execute built-in commands.

@param var                The t_var structure containing the command.
@param index              The index of the command in the pipeline.
@param fd_parent     The file descriptor of the parent process.
@param fd_to_child    A pointer to the file descriptor of the child process.
@return             The exit status of the built-in command execution.
*/
static int	exec_builtins(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_to_child)
{
	int		original_stdout;
	int		original_stdin;

	original_stdout = dup(STDOUT_FILENO);
	original_stdin = dup(STDIN_FILENO);
	if (exec_redirections(var, index, fd_parent, fd_to_child))
		return (g_process.return_code);
	b_routine(var);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exec_redirect_fd(original_stdout, STDOUT_FILENO);
	exec_redirect_fd(original_stdin, STDIN_FILENO);
	return (EXIT_SUCCESS);
}

int	executer(
	t_var *var,
	int index,
	int fd_parent)
{
	int		fd_to_child[2];
	pid_t	pid;

	if (pipe(fd_to_child) == -1)
		return (err(strerror(errno), NULL, errno));
	if (var->n_cmds == 1 && get_arg_type(var->cmd_current) == BUILTIN)
		return (exec_builtins(var, index, fd_parent, fd_to_child));
	pid = fork();
	if (pid < 0)
		return (err(strerror(errno), NULL, errno));
	else if (pid == 0)
	{
		if (exec_redirections(var, index, fd_parent, fd_to_child))
			exit(g_process.return_code);
		if (get_arg_type(var->cmd_current) == BUILTIN)
			exit(b_routine(var));
		else
			exit(exec_command_not_builtin(var));
	}
	else
	{
		close(fd_parent);
		exec_parent_routine(var, index, fd_to_child, pid);
	}
	return (EXIT_SUCCESS);
}
