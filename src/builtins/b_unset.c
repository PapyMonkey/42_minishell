/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:22:56 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/11 01:52:20 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	b_unset(t_var *var)
{
	t_list	*flag;
	t_list	*tmp_env;
	t_list	*tmp_exp;
	int		i;

	i = 0;
	flag = check_arg_flag(var->cmd_current);
	if (flag)
		return (err_d("unset", get_arg_content(flag), "invalid option", 2));
	while (var->command_array[++i])
	{
		if (check_identifier(var->command_array[i]))
			return (err_d("unset", var->command_array[i],
					"not a valid identifier", 1));
		tmp_env = search_env_elem(var->l_env, var->command_array[i]);
		if (tmp_env != NULL)
			ft_lstremove(&(var->l_env), tmp_env, free_env);
		tmp_exp = search_exp_elem(var->l_exp, var->command_array[i]);
		if (tmp_exp != NULL)
			ft_lstremove(&(var->l_exp), tmp_exp, free);
	}
	g_process.return_code = 0;
	return (EXIT_SUCCESS);
}
