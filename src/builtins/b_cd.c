/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:25:16 by bgales            #+#    #+#             */
/*   Updated: 2023/04/07 17:59:25 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_update_env(
	t_var *var,
	char *key,
	char *value)
{
	t_list	*ptr_elem;

	ptr_elem = search_env_elem(var->l_env, key);
	if (!ptr_elem)
		return ;
	free(((t_env *)ptr_elem->content)->value);
	((t_env *)ptr_elem->content)->value = ft_strdup(value);
}

static int	cd_exec(
	t_var *var,
	char * tmp_path)
{
	char	pwd[BUFFER_SIZE];

	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "OLDPWD", pwd);
	if (chdir(tmp_path) != 0)
		return (err_d("cd", tmp_path,
				strerror(errno), errno));
	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "PWD", pwd);
	free(g_process.pwd);
	g_process.pwd = ft_strdup(pwd);
	if (!g_process.pwd)
		return (err("cd", strerror(errno), errno));
	g_process.return_code = 0;
	return (EXIT_SUCCESS);
}

int	b_cd(t_var *var)
{
	int		count;
	t_list	*home;
	t_list	*flag;
	char	*tmp_path;

	tmp_path = var->command_array[1];
	count = count_argument(var->cmd_current);
	if (count == 1 )
	{
		home = search_env_elem(var->l_env, "HOME");
		if (!home)
			return (err("cd", "HOME is not set", 1));
		tmp_path = get_env_value(home);
	}
	flag = check_arg_flag(var->cmd_current);
	if (flag)
		return (err_d("cd", get_arg_content(flag), "invalid option", 2));
	if (count > 2)
		return (err("cd", "too many arguments", 1));
	return (cd_exec(var, tmp_path));
}
