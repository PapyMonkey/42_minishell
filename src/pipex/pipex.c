/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/05 22:32:49 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void print_current_cmd(t_var *var)
{
	if (!var->next_command)
		printf("current cmd : NULL\n");
	else
		printf("current cmd : %s\n", get_arg_content(var->next_command));
}

// Access and execute commands
static void	exec_command(
	t_var *var,
	int *fd)
{
	char	**command;
	char	**path;
	char	**env;
	char	*try_access;

	// if (var->l_arg == NULL)
	// 	write(1, "OK!", 3);
	// ft_putstr_fd("var->l_arg :", 1);
	// ft_putstr_fd(get_arg_content(var->l_arg), 1);
	// ft_putstr_fd("\n", 1);
	// ft_putstr_fd("var->l_arg->type :", 1);
	// ft_putstr_fd(ft_itoa((int)get_arg_type(var->l_arg)), 1);
	command = exec_build_cmd(var->next_command);
	// printf("command[0] = %s\n", command[0]);
	// printf("command[1] = %s\n", command[1]);
	// printf("command[2] = %s\n", command[2]);
	// command = var->table_cmd->cmd_str;
	path = ft_split(
		((t_env *)get_env_elem(var->l_env, "PATH")->content)->value, ':');
	try_access = ft_exec_access(command[0], path);
	free(path);
	if (!try_access)
		err_put_exit_command_not_found(command[0]);
	env = build_env_array(var->l_env);
	execve(try_access, command, env);
	free_2d_char(env);
	free(command);
	free(try_access);
	exit(EXIT_SUCCESS);
}

// static void	exec_routine(
// 	t_var *var,
// 	int index,
// 	int fd_old,
// 	int *fd)
// {
// 	int		fd_child[2];

// 	if (pipe(fd_child) == -1)
// 		err_put_exit();
// 	close(fd[READ_END]);
// 	if (get_arg_type(var->sep_last))
// 	{
// 		printf("Coucou les potes\n");
// 	}
// 	else
// 	{
// 		printf("Coucou les potes\n");
// 	}

// 	// if (index == var->n_cmds)
// 	// 	ft_pipex_redirect(fd_old, STDOUT_FILENO);
// 	// else
// 	// {
// 	// 	if (pipe(fd_child) == -1)
// 	// 		err_put_exit();
// 	// 	ft_pipex_redirect(fd_old, fd_child[READ_END]);
// 	// 	ft_pipex_redirect(fd[WRITE_END], fd_child[WRITE_END]);
// 	// }
// 	// if (i == 1 && ft_strncmp(cmds.args[i], HDOC, ft_strlen(HDOC)) != 0)
// 	// 	ft_pipex_infile(i, fd_child, cmds);
// 	// else if (i == 1 && ft_strncmp(cmds.args[i], HDOC, ft_strlen(HDOC)) == 0)
// 	// 	ft_pipex_here_doc(i, fd_child, cmds);
// 	// else if (i == cmds.args_nb - 1)
// 	// 	ft_pipex_outfile(i, fd_child, cmds);
// 	// else if (i != 1 && i != cmds.args_nb - 1)
// 	// exec_command(i, fd_child, var);

// 	printf("Coucou juste avant l'exec\n");
// 	exec_command(var, fd_child);
// }

static void exec_child_routine(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_child)
{
	printf("Check child - ");
	print_current_cmd(var);
	exec_redirect_fd(fd_parent, STDIN_FILENO); // Connecte l'entrée standard à fd_parent (sortie précédente)
    if (index < var->n_cmds - 1) // Si ce n'est pas la dernière commande
	{
		printf("Check child - pas la derniere commande\n");
		exec_redirect_fd(fd_child[WRITE_END], STDOUT_FILENO); // Connecte la sortie standard au pipe d'entrée
	}
	close(fd_child[READ_END]);
	close(fd_child[WRITE_END]);
	exec_command(var, fd_child);
	exit(EXIT_FAILURE);
}

// TODO: Function to initialize our fd
// Check if :
//		is_there_redirection ? 
//			YES -> new fd = fd_old
//			NO	-> new_fd = brand_new_fd
void executor_v2(
	t_var *var,
	int index,
	int fd_parent)
{
	int		fd_to_child[2];
	pid_t	pid;

	if (pipe(fd_to_child) == -1)
		err_put_exit();
	printf("Check parents - index = %d\n", index);
	pid = fork();
	if (pid < 0)
		err_put_exit();
	else if (pid == 0) // Process fils
		exec_child_routine(var, index, fd_parent, fd_to_child);
	else // Process parent
	{
		close(fd_parent);
		close(fd_to_child[WRITE_END]);
		if (waitpid(pid, NULL, 0) == -1)
			exit(EXIT_FAILURE);
		if (index < var->n_cmds - 1)
		{
			var->next_command = get_command_next(var->l_arg);
			printf("Check parents - ");
			print_current_cmd(var);
			executor_v2(var, ++index, fd_to_child[READ_END]);
		}
		else
			close(fd_to_child[READ_END]);
	}
}
