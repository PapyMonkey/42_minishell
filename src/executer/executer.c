/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 01:18:05 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void print_current_cmd(t_var *var)
{
	if (!var->current_arg)
		printf("current cmd : NULL\n");
	else
		printf("current cmd : %s\n", get_arg_content(var->current_arg));
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
	command = exec_build_cmd(var->current_arg);
	// printf("command[0] = %s\n", command[0]);
	// printf("command[1] = %s\n", command[1]);
	// printf("command[2] = %s\n", command[2]);
	// command = var->table_cmd->cmd_str;
	path = ft_split(
		((t_env *)get_env_elem(var->l_env, "PATH")->content)->value, ':');
	try_access = exec_try_access(command[0], path);
	free(path);
	if (!try_access)
		err_put_exit_command_not_found(command[0]);
	env = exec_build_env(var->l_env);
	execve(try_access, command, env);
	free_2d_char(env);
	free(command);
	free(try_access);
	exit(EXIT_SUCCESS);
}

static void exec_child_routine(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_child)
{
	int	result_redirections;

	printf("Check child - ");
	print_current_cmd(var);
	close(fd_child[READ_END]);
	result_redirections = redir_out_handle(var, fd_parent);
	if (result_redirections == REDIR_OUT || result_redirections == APPEND)
		return ;
	exec_redirect_fd(fd_parent, STDIN_FILENO); // Connecte l'entrée standard à fd_parent (sortie précédente)
	result_redirections = redir_in_handle(var, fd_child[WRITE_END]);
	if (result_redirections == REDIR_IN)
		return ;
	if (index < var->n_cmds + var->n_redirs - 1) // Si ce n'est pas la dernière commande
	{
		printf("Check child - pas la derniere commande\n");
		exec_redirect_fd(fd_child[WRITE_END], STDOUT_FILENO); // Connecte la sortie standard au pipe d'entrée
	}
	close(fd_child[WRITE_END]);
	exec_command(var, fd_child);
	exit(EXIT_SUCCESS); // ? Really useful ?
}
// Plan :
// - if redir_in
// - else if redir_out
// - else if !separateur
//       executer commande

void executer(
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
		if (index < var->n_cmds + var->n_redirs - 1)
		{
			var->current_arg = get_command_or_redir_next(var->current_arg);
			printf("Check parents - ");
			print_current_cmd(var);
			executer(var, ++index, fd_to_child[READ_END]);
		}
		else
			close(fd_to_child[READ_END]);
	}
}
