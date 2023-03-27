/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:48:35 by bgales            #+#    #+#             */
/*   Updated: 2023/03/27 12:35:08 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_flag(t_list **list)
{
	t_list	*ptr;

	ptr = *list;
	if (((t_arg *)ptr->content)->type == ARG)
	{
		while (ptr != NULL && ((t_arg *)ptr->content)->type != PIPE)
		{
			if (((t_arg *)ptr->content)->type == TEXT)
				((t_arg *)ptr->content)->type = ARG;
			ptr = ptr->next;
		}
	}
	if (ptr != NULL && ((t_arg *)ptr->content)->type == PIPE)
		return ;
	if (ptr != NULL && ((t_arg *)ptr->content)->type == TEXT
		&& ((t_arg *)ptr->content)->content[0] == '-')
			((t_arg *)ptr->content)->type = FLAG;
	if (ptr != NULL && ((t_arg *)ptr->content)->type == TEXT
		&& ((t_arg *)ptr->content)->content[0] != '-')
		((t_arg *)ptr->content)->type = ARG;
	if (ptr != NULL && ((t_arg *)ptr->content)->type != ARG)
		ptr = ptr->next;
	if (ptr != NULL)
		is_flag(&ptr);
}

void	type_exec(t_list **list)
{
	t_arg	*arg;

	arg = (*list)->content;
	if (arg->type == PIPE)
		return ;
	if (arg->type == TEXT)
		arg->type = EXEC;
	else
		*list = (*list)->next;
}

void	type_arg(t_list **list)
{
	t_arg	*arg;
	t_list	*ptr;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg->type == PIPE)
			return ;
		if (arg->type == TEXT)
			arg->type = ARG;
		ptr = ptr->next;
	}
}

void	*define_elem(t_list **list)
{
	t_arg	*arg;
	t_list	*ptr;

	ptr = *list;
	arg = ptr->content;
	while (ptr != NULL && ((t_arg *)ptr->content)->type != EXEC
		&& ((t_arg *)ptr->content)->type != PIPE
		&& ((t_arg *)ptr->content)->type != DOLLAR)
		type_exec(&ptr);
	if (ptr != NULL && ((t_arg *)ptr->content)->type != FLAG
		&& ((t_arg *)ptr->content)->type != PIPE
		&& ((t_arg *)ptr->content)->type != DOLLAR)
		is_flag(&ptr);
	if (ptr != NULL && ((t_arg *)ptr->content)->type != ARG
		&& ((t_arg *)ptr->content)->type != PIPE
		&& ((t_arg *)ptr->content)->type != DOLLAR)
		type_arg(&ptr);
	while (ptr != NULL && ((t_arg *)ptr->content)->type != PIPE)
		ptr = ptr->next;
	if (ptr != NULL && ((t_arg *)ptr->content)->type == PIPE)
	{
		ptr = ptr->next;
		define_elem(&ptr);
	}
	return (0);
}
