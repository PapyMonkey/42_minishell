/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:53:41 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 01:59:38 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env_element(char *envp)
{
	t_env	*element;
	int		envp_len;
	int		envp_pos_sep;

	element = malloc(sizeof(t_env));
	if (!element)
		err_exit(strerror(errno), NULL, errno);
	envp_len = ft_strlen(envp);
	envp_pos_sep = 0;
	while (envp[envp_pos_sep] != '=')
		envp_pos_sep++;
	element->key = ft_substr(envp, 0, envp_pos_sep);
	if (!element->key)
		err_exit(strerror(errno), NULL, errno);
	element->value = ft_substr(envp, envp_pos_sep + 1, envp_len);
	if (!element->value)
		err_exit(strerror(errno), NULL, errno);
	return (element);
}

/**
@brief Creates the t_list that contains all the parsed ENV variables.

@param var Variable that will contain all the other useful ones.
@param envp 2D array storing all the ENV variables.
*/
static void	init_env(t_var *var, char **envp)
{
	int		i;
	char	*tmp_str;

	i = -1;
	while (envp[++i])
	{
		ft_lstadd_back(
			&var->l_env,
			ft_lstnew(init_env_element(envp[i]))
			);
	}
	if (!var->l_env)
	{
		tmp_str = ft_strjoin("PWD=", g_process.pwd);
		ft_lstadd_back(
			&var->l_env,
			ft_lstnew(init_env_element(tmp_str))
			);
		free(tmp_str);
	}
}

// NOTE: Documentation
static void	init_pwd(void)
{
	char	pwd[BUFFER_SIZE];

	if (getcwd(pwd, BUFFER_SIZE) == 0)
	{
		if (errno == ERANGE)
			err("pathname length exceeds the buffer size", NULL, 1);
		return ;
	}
	g_process.pwd = ft_strdup(pwd);
	if (!g_process.pwd)
		err_exit(strerror(errno), NULL, errno);
}

t_var	*init(char **envp)
{
	t_var	*var_out;

	var_out = malloc(sizeof(t_var));
	if (!var_out)
		err_exit(strerror(errno), NULL, errno);
	init_pwd();
	var_out->l_arg = NULL;
	var_out->l_env = NULL;
	var_out->l_exp = NULL;
	var_out->cmd_start = NULL;
	var_out->cmd_end = NULL;
	var_out->cmd_current = NULL;
	var_out->next_redir_in = NULL;
	var_out->next_redir_out = NULL;
	var_out->n_cmds = 0;
	var_out->command_array = NULL;
	init_env(var_out, envp);
	return (var_out);
}

int	init_command_context(
	t_var *var,
	char *const input)
{
	int		fd[2];

	g_process.pid = 0;
	var->l_arg = ft_split_args(input, var->l_env);
	var->command_array = NULL;
	reset_cmd_ptrs(var, var->l_arg);
	var->n_cmds = count_command(var->l_arg);
	if (pipe(fd) == -1)
		err_exit(strerror(errno), NULL, errno);
	close(fd[WRITE_END]);
	if (dup2(STDIN_FILENO, fd[READ_END]) == -1)
		err_exit(strerror(errno), NULL, errno);
	return (fd[READ_END]);
}
