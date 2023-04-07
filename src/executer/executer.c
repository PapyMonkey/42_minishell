/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/07 23:34:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_command_not_builtin(t_var *var)
{
	char	**command;
	char	**env;
	char	*try_access;
	char	**path;

	command = var->command_array;
	env = exec_build_env(var->l_env);
	if (access(command[0], X_OK) == 0)
		execve(command[0], command, env);
	else if (!search_env_elem(var->l_env, "PATH")) 
		ft_printf("minishell: %s: no such file or directory\n", command[0]);
	else
	{
		path = ft_split(
			get_env_value(search_env_elem(var->l_env, "PATH")),
			':');
		try_access = exec_try_access(command[0], path);
		free(path);
		if (!try_access)
			err_put_exit_command_not_found(command[0]);
		execve(try_access, command, env);
		free(try_access);
	}
	free_2d_char(env);
}

// Access and execute commands
static void	exec_command(t_var *var)
{
	var->command_array= exec_build_cmd(var->current_arg);
	if (get_arg_type(var->current_arg) == BUILTIN)
		b_routine(var);
	else
		exec_command_not_builtin(var);
	free(var->command_array);
	// exit(EXIT_SUCCESS); // NOTE: Really useful ?
}

static void exec_child_routine(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_child)
{
	int	result_redirections;

	close(fd_child[READ_END]);
	result_redirections = redir_out_handle(var, fd_parent);
	if (result_redirections == REDIR_OUT || result_redirections == APPEND)
		exit(EXIT_SUCCESS);
	result_redirections = redir_heredoc_handle(var, fd_child[WRITE_END]);
	if(result_redirections == HERE_DOC)
		exit(EXIT_SUCCESS);
	exec_redirect_fd(fd_parent, STDIN_FILENO);
	result_redirections = redir_in_handle(var, fd_child[WRITE_END]);
	if (result_redirections == REDIR_IN)
		exit(EXIT_SUCCESS);
	if (index < var->n_cmds + var->n_redirs - 1)
		exec_redirect_fd(fd_child[WRITE_END], STDOUT_FILENO);
	close(fd_child[WRITE_END]);
	exec_command(var);
}

// NOTE: Documentation
static void exec_parent_routine(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_to_child,
	pid_t pid)
{
	close(fd_parent);
	close(fd_to_child[WRITE_END]);
	if (waitpid(pid, NULL, 0) == -1)
		exit(EXIT_FAILURE);
	if (index < var->n_cmds + var->n_redirs - 1)
	{
		var->current_arg = get_command_or_redir_next(var->current_arg);
		executer(var, ++index, fd_to_child[READ_END]);
	}
	else
		close(fd_to_child[READ_END]);
}

void executer(
	t_var *var,
	int index,
	int fd_parent)
{
	int		fd_to_child[2];
	pid_t	pid;

	if (var->n_cmds == 1 && get_arg_type(var->l_arg) == BUILTIN)
	{
		var->command_array = exec_build_cmd(var->current_arg);
		b_routine(var);
		free(var->command_array);
		return ;
	}
	if (pipe(fd_to_child) == -1)
		err_put_exit();
	pid = fork();
	if (pid < 0)
		err_put_exit();
	else if (pid == 0)
		exec_child_routine(var, index, fd_parent, fd_to_child);
	else
		exec_parent_routine(var, index, fd_parent, fd_to_child, pid);
}
