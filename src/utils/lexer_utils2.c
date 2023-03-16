/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:33:15 by bgales            #+#    #+#             */
/*   Updated: 2023/03/14 16:58:26 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*join_all(t_list **list)
{
	t_list	*ret;
	t_list	*ptr;
	t_arg	*arg;

	ret = NULL;
	ptr = *list;
	arg = malloc(sizeof(t_arg));
	arg->content = NULL;
	while (ptr != NULL)
	{
		arg->content = minishell_join(arg->content,
				((t_arg *)(ptr)->content)->content);
		ptr = ptr->next;
	}
	arg->type = TEXT;
	ret = ft_lstnew(arg);
	ft_lstclear(list, free_lstcontent);
	return (ret);
}

int	no_whitespace(t_list *list)
{
	while (list != NULL)
	{
		if (((t_arg *)(list)->content)->type == WHITE_SPACE)
			return (1);
		list = list->next;
	}
	return (0);
}

void	*del_whitespace(t_list **list)
{
	t_list	*ptr;
	t_list	*tmp;
	t_arg	*arg;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg->type == WHITE_SPACE)
		{
			tmp = ptr;
			ptr = ptr->next;
			arg = ptr->content;
			ft_lstremove(list, tmp, free_lstcontent);
		}
		if (arg->type != WHITE_SPACE)
			ptr = ptr->next;
	}
	return (0);
}

int	no_quote(t_list **list)
{
	t_list	*ptr;
	t_arg	*arg;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg->type == QUOTE || arg->type == D_QUOTE
			|| arg->type == OPEN_D_QUOTE || arg->type == CLOSE_D_QUOTE
			|| arg->type == OPEN_QUOTE || arg->type == CLOSE_QUOTE)
			break ;
		ptr = ptr->next;
	}
	if (ptr == NULL)
		return (1);
	else
		return (0);
}
