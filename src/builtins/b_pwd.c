/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:45:15 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/06 04:12:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_pwd(t_list *const l_env)
{
	t_list	*tmp;

	tmp = get_env_elem(l_env, "PWD");
	if (tmp->next == NULL)
	{
		ft_printf("No PWD variable defined.\n");
		return ;
	}
	print_env_elem(tmp->content);
}
