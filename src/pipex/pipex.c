/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:45:07 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pipex_here_doc(size_t i, int *fd, t_cmds cmds)
{
	char	*limiter;
	char	*out;

	limiter = ft_strjoin(cmds.args[i + 1], "\n");
	out = ft_get_next_line(STDIN_FILENO);
	if (!out)
		err_put_exit();
	while (ft_strncmp(out, limiter, ft_strlen(limiter)))
	{
		if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
			err_put_exit();
		out = ft_get_next_line(STDIN_FILENO);
	}
	free(limiter);
	free(out);
	close(fd[WRITE_END]);
	exit(EXIT_SUCCESS);
}

// Access and execute commands
static void	exec_command(
	t_var *var,
	int index,
	int *fd)
{
	char	**command;
	char	**path;
	char	**env;
	char	*try_access;

	command = exec_build_cmd(var->l_arg);
	// command = var->table_cmd->cmd_str;
	path = ft_split((char *)get_env_elem(var->l_env, "PATH")->content, ':');
	int n=-1;
	while (path[++n])
		printf("%s\n", path[n]);
	try_access = ft_exec_access(command[0], path);
	free(path);
	printf("try_access = %s\n", try_access);
	if (!try_access)
		err_put_exit_command_not_found(command[0]);
	write(1, "Coucou les potes\n", 15);
	ft_pipex_redirect(fd[READ_END], STDIN_FILENO);
	ft_pipex_redirect(fd[WRITE_END], STDOUT_FILENO);
	env = build_env_array(var->l_env);
	execve(try_access, command, env);
	free_2d_char(env);
	free(command);
	free(try_access);
	exit(EXIT_SUCCESS);
}

// static void handle_redirections(
// 	t_var *var,
// 	int	index,
// 	int fd_old,
// 	int fd_new)
// {
// 	t_list	*previous_separator;
//
// 	previous_separator = get_previous_sep(var, index);
// 	if (!previous_separator)
// 	{
// 		
// 	}
// 	else if (get_arg_type(previous_separator) == PIPE)
// 	{
//
// 	}
// }

static void	exec_routine(
	t_var *var,
	int index,
	int fd_old,
	int *fd)
{
	int		fd_child[2];

	if (pipe(fd_child) == -1)
		err_put_exit();
	close(fd[READ_END]);
	if (get_arg_type(var->sep_last))
		jfdlkajfkla;
	else
	{
		
	}

	// if (index == var->n_cmds)
	// 	ft_pipex_redirect(fd_old, STDOUT_FILENO);
	// else
	// {
	// 	if (pipe(fd_child) == -1)
	// 		err_put_exit();
	// 	ft_pipex_redirect(fd_old, fd_child[READ_END]);
	// 	ft_pipex_redirect(fd[WRITE_END], fd_child[WRITE_END]);
	// }
	// if (i == 1 && ft_strncmp(cmds.args[i], HDOC, ft_strlen(HDOC)) != 0)
	// 	ft_pipex_infile(i, fd_child, cmds);
	// else if (i == 1 && ft_strncmp(cmds.args[i], HDOC, ft_strlen(HDOC)) == 0)
	// 	ft_pipex_here_doc(i, fd_child, cmds);
	// else if (i == cmds.args_nb - 1)
	// 	ft_pipex_outfile(i, fd_child, cmds);
	// else if (i != 1 && i != cmds.args_nb - 1)
	// exec_command(i, fd_child, var);

	printf("Coucou juste avant l'exec\n");
	exec_command(i, fd_child, var);
}

// static void	exec_routine(
// 	t_var *var,
// 	int index)
// {
//
// }

void	executor_v2(
	t_var *var,
	int index,
	int fd_old)
{
	int		fd[2];
	pid_t	pid;

	// if (index >= var->n_cmds)
	// 	return ;
	// TODO: Function to initialize our fd
	if (pipe(fd) == -1)
		err_put_exit();
	pid = fork();
	// printf("PID : %d\n", pid);
	if (pid < 0)
		err_put_exit();
	else if (pid == 0)
		exec_routine(var, index, fd_old, fd);
	else
	{
		close(fd_old);
		close(fd[WRITE_END]);
		// NOTE: Pourquoi ?
		if (waitpid(pid, NULL, 0) == -1)
			exit(EXIT_FAILURE);
		// if (!ft_strncmp(cmds.args[i], HDOC, ft_strlen(HDOC)))
		// 	ft_pipex_core(i + 2, fd[READ_END], cmds);
		// else
		executor_v2(var, ++index, fd[READ_END]);
	}
}
