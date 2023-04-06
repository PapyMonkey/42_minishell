/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:34:45 by bgales            #+#    #+#             */
/*   Updated: 2023/04/06 17:38:53 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Documentation
static void	join_quotes_ext(t_list **save, t_list **ret)
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

// TODO: Documentation
static void	j_quotes_norm(t_list **ptr, t_list **save, t_list **ret)
{
	*ptr = (*ptr)->next;
	*save = *ptr;
	while (*ptr != NULL && ((t_arg *)(*ptr)->content)->type != WHITE_SPACE
		&& ((t_arg *)(*ptr)->content)->type != OPEN_D_QUOTE
		&& ((t_arg *)(*ptr)->content)->type != OPEN_QUOTE)
		*ptr = (*ptr)->next;
	if (*ptr != NULL && (((t_arg *)(*ptr)->content)->type == OPEN_D_QUOTE
		|| ((t_arg *)(*ptr)->content)->type == OPEN_QUOTE))
		join_quotes_ext(save, ret);
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

// TODO: Documentation
static void	join_text_ext(t_list **ptr, t_list **tmp, t_list **save)
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

void	join_text(t_list **list)
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
			join_text_ext(&ptr, &tmp, &save);
			break ;
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}
