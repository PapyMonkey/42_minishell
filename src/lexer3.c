/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:33:13 by bgales            #+#    #+#             */
/*   Updated: 2023/03/13 16:07:05 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	to_next_quote(t_list **lst, char *quote)
{
	t_arg	*arg;

	arg = (*lst)->content;
	if (!ft_strncmp(arg->content, quote, 1))
	{
		if (arg->type == D_QUOTE)
			arg->type = OPEN_D_QUOTE;
		else
			arg->type = OPEN_QUOTE;
		*lst = (*lst)->next;
		arg = (*lst)->content;
		while (*lst != NULL && ft_strncmp(arg->content, quote, 1))
		{
			*lst = (*lst)->next;
			arg = (*lst)->content;
		}
		if (arg->type == D_QUOTE)
			arg->type = CLOSE_D_QUOTE;
		else
			arg->type = CLOSE_QUOTE;
	}
}

void	*open_close_quote(t_list **lst)
{
	t_arg	*arg;
	t_list	*ptr;

	ptr = *lst;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (!ft_strncmp(arg->content, "\'", 1))
			to_next_quote(&ptr, arg->content);
		if (!ft_strncmp(arg->content, "\"", 1))
			to_next_quote(&ptr, arg->content);
		ptr = ptr->next;
	}
	return (0);
}

void	*join_in_quotes_2(t_list **dst, t_list **src)
{
	t_arg	*arg;
	t_arg	*cpy;

	if (((t_arg *)(*src)->content)->type == CLOSE_D_QUOTE
		|| ((t_arg *)(*src)->content)->type == CLOSE_QUOTE)
	{
		ft_lstadd_back(dst, ft_lstnew(t_arg_cpy((*src)->content)));
		return (0);
	}
	cpy = malloc(sizeof(t_arg));
	cpy->content = NULL;
	while (((t_arg *)(*src)->content)->type != CLOSE_D_QUOTE &&
		((t_arg *)(*src)->content)->type != CLOSE_QUOTE)
	{
		cpy->content = minishell_join(cpy->content,
				((t_arg *)(*src)->content)->content);
		(*src) = (*src)->next;
		cpy->type = TEXT;
	}
	ft_lstadd_back(dst, ft_lstnew(cpy));
	ft_lstadd_back(dst, ft_lstnew(t_arg_cpy((*src)->content)));
	return (0);
}

void	*join_in_quotes(t_list **lst)
{
	t_list	*ret;
	t_list	*ptr;
	t_arg	*arg;

	ptr = *lst;
	ret = NULL;
	while (ptr != NULL)
	{
		arg = ptr->content;
		ft_lstadd_back(&ret, ft_lstnew(t_arg_cpy(arg)));
		if (arg->type == OPEN_D_QUOTE || arg->type == OPEN_QUOTE)
		{
			ptr = ptr->next;
			join_in_quotes_2(&ret, &ptr);
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
	ft_lstclear(lst, free_lstcontent);
	return (ret);
}

t_list	*struct_init_2(t_list **list)
{
	if (!no_quote(list))
	{
		open_close_quote(list);
		*list = join_in_quotes(list);
		empty_quotes(list);
		while (!no_quote(list))
			join_quotes(list);
		join_text(list);
	}
	define_elem(list);
	del_whitespace(list);
	return (*list);
}
