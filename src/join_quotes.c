/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:49:43 by bgales            #+#    #+#             */
/*   Updated: 2023/03/13 16:04:17 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*mid_jquote2(t_list **ptr, t_arg **new)
{
	while (*ptr != NULL)
	{
		if (((t_arg *)(*ptr)->content)->type == WHITE_SPACE)
			break ;
		if ((((t_arg *)(*ptr)->content)->type != OPEN_D_QUOTE
			&& ((t_arg *)(*ptr)->content)->type != OPEN_QUOTE
			&& ((t_arg *)(*ptr)->content)->type != CLOSE_D_QUOTE
			&& ((t_arg *)(*ptr)->content)->type != CLOSE_QUOTE)
			&& (*ptr)->next != NULL)
				(*new)->content = minishell_join((*new)->content,
					((t_arg *)(*ptr)->content)->content);
		if (*ptr != NULL)
			*ptr = (*ptr)->next;
	}
}

void	*end_jquote2(t_list **ptr, t_list **list, t_arg **new)
{
	*list = *ptr;
	(*new)->type = TEXT;
	ft_lstadd_front(list, ft_lstnew(t_arg_cpy(*new)));
	free ((*new)->content);
	free (*new);
}

t_list	*join_quotes_2(t_list **list)
{
	t_arg	*new;
	t_list	*ptr;
	t_list	*tmp;

	ptr = *list;
	new = malloc(sizeof(t_arg));
	new->content = NULL;
	mid_jquote2(&ptr, &new);
	tmp = ptr;
	ptr = *list;
	while (ptr != NULL && ((t_arg *)(ptr)->content)->type != WHITE_SPACE)
	{
		ptr = ptr->next;
		ft_lstdelone(*list, free_lstcontent);
		*list = ptr;
	}
	end_jquote2(&ptr, list, &new);
	return (*list);
}

void	*norm_jquotes(t_list **ptr, t_list **tmp)
{
	while (*ptr != NULL && ((t_arg *)(*ptr)->content)->type != OPEN_D_QUOTE
		&& ((t_arg *)(*ptr)->content)->type != OPEN_QUOTE)
	{
		if (((t_arg *)(*ptr)->content)->type == WHITE_SPACE)
		{
			*ptr = (*ptr)->next;
			*tmp = *ptr;
			break ;
		}
		*ptr = (*ptr)->next;
	}
	while (*tmp != NULL && ((t_arg *)(*tmp)->content)->type != WHITE_SPACE
		&& ((t_arg *)(*tmp)->content)->type != OPEN_D_QUOTE
		&& ((t_arg *)(*tmp)->content)->type != OPEN_QUOTE)
		*tmp = (*tmp)->next;
}

void	*join_quotes(t_list **list)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *list;
	tmp = *list;
	norm_jquotes(&ptr, &tmp);
	if (tmp == NULL)
		return (0);
	if (((t_arg *)(tmp)->content)->type == WHITE_SPACE)
	{
		join_quotes(&tmp);
		return (0);
	}
	if (((t_arg *)(tmp)->content)->type == OPEN_D_QUOTE
		|| ((t_arg *)(tmp)->content)->type == OPEN_QUOTE)
		join_quotes_2(&ptr);
	(*list)->next = ptr;
}
