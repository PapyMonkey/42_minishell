/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:18:41 by bgales            #+#    #+#             */
/*   Updated: 2023/03/13 15:55:42 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*join_text_2(t_list **ptr, t_list **tmp, t_list **save)
{
	while (*ptr != NULL && ((t_arg *)(*ptr)->content)->type == TEXT)
	{
		((t_arg *)(*tmp)->content)->content = minishell_join(
				((t_arg *)(*tmp)->content)->content,
				((t_arg *)(*ptr)->content)->content);
		*ptr = (*ptr)->next;
	}
	(*ptr) = (*tmp)->next;
	while (*ptr != NULL && ((t_arg *)(*ptr)->content)->type == TEXT)
	{
		*save = (*ptr)->next;
		ft_lstdelone(*ptr, free_lstcontent);
		*ptr = *save;
	}
	(*tmp)->next = *save;
}

void	*join_text(t_list **list)
{
	t_list	*ptr;
	t_list	*tmp;
	t_list	*save;

	ptr = *list;
	while (ptr != NULL)
	{
		while (((t_arg *)(ptr)->content)->type == TEXT)
		{
			tmp = ptr;
			ptr = ptr->next;
			if (ptr == NULL || ((t_arg *)(ptr)->content)->type != TEXT)
				break ;
			join_text_2(&ptr, &tmp, &save);
			break ;
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}
