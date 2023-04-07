/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:22:56 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/07 23:26:19 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_unset(t_var *var)
{
	t_list	*tmp;
	int		i;
	
	i = 0;
	while (var->command_array[++i])
	{
		tmp = search_env_elem(var->l_env, var->command_array[i]);
		if (tmp == NULL)
			continue ;
		ft_lstremove(&(var->l_env), tmp, free_env);
	}
}
