/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:21:38 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 04:10:49 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_env(t_var *const var)
{
	t_list	*tmp;

	if (var->current_arg->next)
		return (err("env", "invalid option", 125));
	tmp = var->l_env;
	ft_lstiter(tmp, print_env_elem);
	g_process.return_code = 0;
}
