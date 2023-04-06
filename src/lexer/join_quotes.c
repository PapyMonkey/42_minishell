/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:34:45 by bgales            #+#    #+#             */
/*   Updated: 2023/03/27 12:35:58 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	join_quotes_2(t_list **save, t_list **ret)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->content = NULL;
	while (*save != NULL && ((t_arg *)(*save)->content)->type != WHITE_SPACE)
	{
		while (*save != NULL && ((((t_arg *)
						(*save)->content)->type == OPEN_QUOTE
					|| ((t_arg *)(*save)->content)->type == OPEN_D_QUOTE
				|| ((t_arg *)(*save)->content)->type == CLOSE_QUOTE
			|| ((t_arg *)(*save)->content)->type == CLOSE_D_QUOTE)))
			*save = (*save)->next;
		if (*save != NULL && ((t_arg *)(*save)->content)->type != WHITE_SPACE)
			arg->content = minishell_join(arg->content,
					((t_arg *)(*save)->content)->content);
		if (*save != NULL && ((t_arg *)(*save)->content)->type != WHITE_SPACE)
			*save = (*save)->next;
	}
	arg->type = TEXT;
	ft_lstadd_back(ret, ft_lstnew(arg));
}

void	j_quotes_norm(t_list **ptr, t_list **save, t_list **ret)
{
	*ptr = (*ptr)->next;
	*save = *ptr;
	while (*ptr != NULL && ((t_arg *)(*ptr)->content)->type != WHITE_SPACE
		&& ((t_arg *)(*ptr)->content)->type != OPEN_D_QUOTE
		&& ((t_arg *)(*ptr)->content)->type != OPEN_QUOTE)
		*ptr = (*ptr)->next;
	if (*ptr != NULL && (((t_arg *)(*ptr)->content)->type == OPEN_D_QUOTE
		|| ((t_arg *)(*ptr)->content)->type == OPEN_QUOTE))
		join_quotes_2(save, ret);
	else
	{
		while (*save != NULL && ((t_arg *)
				(*save)->content)->type != WHITE_SPACE)
		{
			if (*save == NULL)
				break ;
			ft_lstadd_back(ret, ft_lstnew(t_arg_cpy(
						((t_arg *)(*save)->content))));
			*save = (*save)->next;
		}
	}
	*ptr = *save;
}

t_list	*join_quotes(t_list **list)
{
	t_list	*ret;
	t_list	*ptr;
	t_list	*save;

	ptr = *list;
	ret = NULL;
	while (ptr != NULL)
	{
		if (((t_arg *)(ptr)->content)->type != OPEN_D_QUOTE
			&& ((t_arg *)(ptr)->content)->type != OPEN_QUOTE
			&& ((t_arg *)(ptr)->content)->type != CLOSE_QUOTE
			&& ((t_arg *)(ptr)->content)->type != CLOSE_D_QUOTE)
			ft_lstadd_back(&ret, ft_lstnew(t_arg_cpy
					(((t_arg *)(ptr)->content))));
		if (((t_arg *)(ptr)->content)->type == WHITE_SPACE)
			j_quotes_norm(&ptr, &save, &ret);
		if (ptr != NULL && ((t_arg *)(ptr)->content)->type != WHITE_SPACE)
			ptr = ptr->next;
	}
	ft_lstclear(list, free_lstcontent);
	return (ret);
}
