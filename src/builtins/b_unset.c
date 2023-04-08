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

void	b_unset(t_var *var)
{
	t_list	*tmp_env;
	t_list	*tmp_exp;
	int		i;

	i = 0;
	while (var->command_array[++i])
	{
		tmp_env = search_env_elem(var->l_env, var->command_array[i]);
		if (tmp_env != NULL)
			ft_lstremove(&(var->l_env), tmp_env, free_env);
		tmp_exp = search_exp_elem(var->l_exp, var->command_array[i]);
		if (tmp_exp != NULL)
			ft_lstremove(&(var->l_exp), tmp_exp, free);
	}
}
