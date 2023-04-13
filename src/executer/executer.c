/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/12 14:52:53 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: Documentation
static void	exec_command_not_builtin(t_var *var)
{
	char	**env;
	char	**path;
	char	*try_access;

	var->command_array = exec_build_cmd(var->current_arg);
	if (!var->command_array[0])
		return ;
	env = exec_build_env(var->l_env);
	if (access(var->command_array[0], X_OK) == 0)
		execve(var->command_array[0], var->command_array, env);
	else if (!search_env_elem(var->l_env, "PATH")) 
		err_exit(var->command_array[0], "No such file or directory", 127);
	else
	{
		path = ft_split(
			get_env_value(search_env_elem(var->l_env, "PATH")),
			':');
		try_access = exec_try_access(var->command_array[0], path);
		if (!try_access)
			err_exit(var->command_array[0], strerror(errno), 127);
		execve(try_access, var->command_array, env);
		free_2d_char(path);
		free(try_access);
	}
	free_2d_char(env);
}

// NOTE: Documentation
static void	exec_command_wrapper(t_var *var)
{
	if (get_arg_type(var->current_arg) == BUILTIN)
		b_routine(var);
	else
		exec_command_not_builtin(var);
	exit(g_process.return_code);
}

// NOTE: Documentation
static void exec_redirections(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_child)
{
	int	result_redirections_in;
	int	result_redirections_out;

	close(fd_child[READ_END]);
	result_redirections_in = -1;
	result_redirections_out = -1;
	while (var->current_arg && is_redir_in(var->current_arg))
		result_redirections_in = redir_in_handle(var);
	printf("result_redirections in : %d\n", result_redirections_in);
	if(!(result_redirections_in == HERE_DOC
		|| result_redirections_in == REDIR_IN))
	{
		printf("Check REDIR_IN\n");
		exec_redirect_fd(fd_parent, STDIN_FILENO);
	}
	while (var->next_redir_out && is_redir_out(var->next_redir_out))
		result_redirections_out = redir_out_handle(var);
	printf("result_redirections out : %d\n", result_redirections_out);
	if (!(result_redirections_out == REDIR_OUT
		|| result_redirections_out == APPEND)
		&& index < var->n_cmds - 1)
	{
		printf("Check REDIR_OUT\n");
		exec_redirect_fd(fd_child[WRITE_END], STDOUT_FILENO);
	}
	close(fd_parent);
	close(fd_child[WRITE_END]);
	printf("CHECK PRINT\n");
	ft_lstiter(var->l_arg, *print_arg_elem);
	g_process.return_code = 0;
}

// FIX :
// - [ ] Retour d'erreur en cas de fichier non trouve
// - [X] Regrouper les redirections en fonction de in ou out
// - [ ] HEREDOC : utiliser un fichier tampon
// - [X] Supprimer les redirections out effectuees de la chaine de caractere

// NOTE : Documentation
static void exec_parent_routine(
	t_var *var,
	int index,
	int fd_parent,
	int *fd_to_child,
	pid_t pid)
{
	close(fd_parent);
	close(fd_to_child[WRITE_END]);
	if (index < var->n_cmds - 1)
	{
		var->current_arg = get_command_or_redir_next(var->current_arg);
		var->next_redir_out = get_next_redir_out(var->current_arg);
		executer(var, ++index, fd_to_child[READ_END]);
	}
	close(fd_to_child[READ_END]);
	g_process.pid = pid;
	waitpid(pid, &g_process.return_code, 0);
	g_process.return_code = WEXITSTATUS(g_process.return_code);
}

void executer(
	t_var *var,
	int index,
	int fd_parent)
{
	int		fd_to_child[2];
	int		original_stdout;
	pid_t	pid;

	if (pipe(fd_to_child) == -1)
		err_exit(strerror(errno), NULL, errno);
	if (var->n_cmds == 1 && get_arg_type(var->l_arg) == BUILTIN)
	{
		original_stdout = dup(STDOUT_FILENO);
		exec_redirections(var, index, fd_parent, fd_to_child);
		// exec_command_wrapper(var);
		b_routine(var);
		close(STDOUT_FILENO);
		exec_redirect_fd(original_stdout, STDOUT_FILENO);
		return ;
	}
	pid = fork();
	if (pid < 0)
		err_exit(strerror(errno), NULL, errno);
	else if (pid == 0)
	{
		exec_redirections(var, index, fd_parent, fd_to_child);
		exec_command_wrapper(var);
	}
	else
		exec_parent_routine(var, index, fd_parent, fd_to_child, pid);
}
