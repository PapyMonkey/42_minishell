/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:40:08 by bgales            #+#    #+#             */
/*   Updated: 2023/03/16 13:57:38 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	empty_quotes_2(t_list **ptr, t_list **tmp, t_list**save)
{
	free (((t_arg *)(*tmp)->content)->content);
	((t_arg *)(*tmp)->content)->content = ft_strdup("\0");
	((t_arg *)(*tmp)->content)->type = TEXT;
	*save = *tmp;
	*tmp = *ptr;
	*ptr = (*ptr)->next;
	ft_lstdelone(*tmp, free_lstcontent);
	(*save)->next = *ptr;
}

void	empty_quotes(t_list **list)
{
	t_list	*ptr;
	t_list	*tmp;
	t_list	*save;

	ptr = *list;
	while (ptr != NULL)
	{
		if (((t_arg *)(ptr)->content)->type == OPEN_D_QUOTE
			|| ((t_arg *)(ptr)->content)->type == OPEN_QUOTE)
		{
			tmp = ptr;
			ptr = ptr->next;
			if (((t_arg *)(ptr)->content)->type == CLOSE_D_QUOTE
				|| ((t_arg *)(ptr)->content)->type == CLOSE_QUOTE)
				empty_quotes_2(&ptr, &tmp, &save);
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}
