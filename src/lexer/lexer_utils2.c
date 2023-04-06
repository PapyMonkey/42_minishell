/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:33:15 by bgales            #+#    #+#             */
/*   Updated: 2023/04/03 17:22:41 by bgales           ###   ########.fr       */
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
	if (arg->content[0] != '$')
		arg->type = TEXT;
	else
		arg->type = DOLLAR;
	ret = ft_lstnew(arg);
	ft_lstclear(list, free_lstcontent);
	return (ret);
}

int	no_redir_no_whitespace(t_list	*list)
{
	t_arg	*arg;

	while (list != NULL)
	{
		arg = list->content;
		if (arg->type == REDIR_IN || arg->type == PIPE || arg->type == REDIR_OUT
			|| arg->type == APPEND || arg->type == HERE_DOC
			|| arg->type == WHITE_SPACE)
			return (1);
		list = list->next;
	}
	return (0);
}

t_list	*del_whitespace(t_list **list)
{
	t_list	*ret;
	t_list	*ptr;
	t_arg	*arg;

	ret = NULL;
	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg->type != WHITE_SPACE)
			ft_lstadd_back(&ret, ft_lstnew(t_arg_cpy(arg)));
		ptr = ptr->next;
	}
	ft_lstclear(list, free_lstcontent);
	return (ret);
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
