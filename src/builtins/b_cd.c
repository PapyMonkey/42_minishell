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

// NOTE: Documentation
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

void	b_cd(t_var *var)
{
	int		count;
	t_list	*flag;
	char	pwd[BUFFER_SIZE];

	count = count_argument(var->cmd_current);
	if (count == 1)
		return (err("cd", "no arguments", 1));
	flag = check_arg_flag(var->cmd_current);
	if (flag)
		return (err_d("cd", get_arg_content(flag), "invalid option", 2));
	if (count > 2)
		return (err("cd", "too many arguments", 1));
	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "OLDPWD", pwd);
	if (chdir(var->command_array[1]) != 0)
		return (err_d("cd", var->command_array[1],
				strerror(errno), errno));
	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "PWD", pwd);
	free(g_process.pwd);
	g_process.pwd = ft_strdup(pwd);
	if (!g_process.pwd)
		return (err("cd", strerror(errno), errno));
	g_process.return_code = 0;
}
