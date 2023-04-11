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
	t_list	*flag;
	char	pwd[BUFFER_SIZE];

	if (!get_number_arguments(var->current_arg->next))
		return (err("cd", "no arguments", 1));
	flag = check_arg_flag(var->current_arg);
	if (flag)
		return (err_d("cd", get_arg_content(flag), "invalid option", 2));
	if (get_number_arguments(var->current_arg->next) > 1)
		return (err("cd", "too many arguments", 1));
	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "OLDPWD", pwd);
	if (chdir(var->command_array[1]) != 0)
		return (err_d("cd", get_arg_content(var->current_arg->next),
				strerror(errno), errno));
	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "PWD", pwd);
	free(g_process.pwd);
	g_process.pwd = ft_strdup(pwd);
	if (!g_process.pwd)
		return (err("cd", strerror(errno), errno));
	g_process.return_code = 0;
}
