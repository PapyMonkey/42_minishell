/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:33:13 by bgales            #+#    #+#             */
/*   Updated: 2023/04/07 18:49:55 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Advances the pointer to the next quote in the list
@param lst The list to navigate
@param quote The quote to match
*/
static void	to_next_quote(t_list **lst, char *quote)
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

/*
@brief Joins the content inside quotes and adds to the destination list
@param dst Pointer to the destination list
@param src Pointer to the source list
@return 0 (null pointer)
*/
static void	*join_in_quotes_2(t_list **dst, t_list **src)
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

/*
@brief Joins content inside quotes in the list
@param lst Pointer to the list of arguments
@return The modified list with joined content
*/
static void	*join_in_quotes(t_list **lst)
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

t_list	*struct_init_2(t_list **list)
{
	if (!no_quote(list))
	{
		*list = join_in_quotes(list);
		empty_quotes(list);
		*list = join_quotes(list);
	}
	join_text(list);
	if (!no_redir_no_whitespace(*list))
		*list = join_all(list);
	*list = del_whitespace(list);
	define_redir(list);
	define_elem(list);
	define_builtins(list);
	return (*list);
}
