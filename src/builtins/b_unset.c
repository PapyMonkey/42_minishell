/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:22:56 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 05:46:56 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_unset(t_list *l_env, const char *str)
{
	int		i;
	t_list	*tmp;

	i = 5;

	while (ft_isspace(str[i]) && str[i])
		i++;
	tmp = get_env_elem(l_env, str + i);
	if (tmp->next == NULL)
		return ;
	ft_lstremove(&l_env, tmp, free_env);
}
