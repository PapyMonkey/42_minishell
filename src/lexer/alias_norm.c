/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:10:42 by bgales            #+#    #+#             */
/*   Updated: 2023/04/14 14:17:43 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	here_doc_skip(t_list **ret, t_list **ptr)
{
	while (*ptr != NULL && get_arg_type(*ptr)
		!= TEXT && get_arg_type(*ptr) != DOLLAR)
	{
		ft_lstadd_back(ret, ft_lstnew(t_arg_cpy((t_arg *)(*ptr)->content)));
		*ptr = (*ptr)->next;
	}
	if ((*ptr) == NULL)
		return ;
	((t_arg *)(*ptr)->content)->type = DELIM;
	ft_lstadd_back(ret, ft_lstnew(t_arg_cpy((t_arg *)(*ptr)->content)));
	(*ptr) = (*ptr)->next;
	return ;
}

void	quote_skip(t_list **ret, t_list **ptr)
{
	while (((t_arg *)(*ptr)->content)->type != CLOSE_QUOTE)
	{
		ft_lstadd_back(ret, ft_lstnew(t_arg_cpy((t_arg *)(*ptr)->content)));
		*ptr = (*ptr)->next;
	}
}
