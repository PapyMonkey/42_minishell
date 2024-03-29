/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:40:08 by bgales            #+#    #+#             */
/*   Updated: 2023/04/06 17:57:37 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(int type)
{
	if (type == OPEN_D_QUOTE || type == CLOSE_D_QUOTE
		|| type == OPEN_QUOTE || type == CLOSE_QUOTE)
		return (1);
	return (0);
}

t_list	*del_quotes(t_list **list)
{
	t_list	*ptr;
	t_list	*ret;

	ptr = *list;
	ret = NULL;
	while (ptr != NULL)
	{
		if (is_quote(get_arg_type(ptr)))
			ptr = ptr->next;
		if (ptr != NULL)
		{
			ft_lstadd_back(&ret, ft_lstnew(t_arg_cpy(ptr->content)));
			ptr = ptr->next;
		}
	}
	ft_lstclear(list, free_lstcontent);
	return (ret);
}

static void	empty_quotes_ext(t_list **ptr, t_list **tmp, t_list**save)
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
				empty_quotes_ext(&ptr, &tmp, &save);
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}
