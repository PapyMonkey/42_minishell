/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:33:13 by bgales            #+#    #+#             */
/*   Updated: 2023/03/05 16:58:49 by bgales           ###   ########.fr       */
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
	t_list	*head;

	head = *lst;
	while (head != NULL)
	{
		arg = head->content;
		if (!ft_strncmp(arg->content, "\'", 1))
			to_next_quote(&head, arg->content);
		if (!ft_strncmp(arg->content, "\"", 1))
			to_next_quote(&head, arg->content);
		head = head->next;
	}
	return (0);
}

t_list	*struct_init_2(t_list *ret)
{
	open_close_quote(&ret);
	ft_lstiter(ret, *print_arg_elem);
}
