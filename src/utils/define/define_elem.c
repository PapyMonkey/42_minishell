/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:48:35 by bgales            #+#    #+#             */
/*   Updated: 2023/04/10 12:38:27 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Set the type of elements in the list to FLAG.

@param list    The list of arguments.
*/
static void	is_flag(t_list **list)
{
	t_list	*ptr;
	t_arg	*arg;

	ptr = *list;
	arg = ptr->content;
	if (arg->type == ARG)
	{
		while (ptr != NULL && !delim_or_rifile(arg->type))
		{
			arg = ptr->content;
			if (arg->type == TEXT)
				arg->type = ARG;
			ptr = ptr->next;
		}
	}
	if (ptr != NULL && (arg->type == PIPE || delim_or_rifile(arg->type)))
		return ;
	if (ptr != NULL && arg->type == TEXT && arg->content[0] == '-')
		arg->type = FLAG;
	if (ptr != NULL && arg->type != ARG)
		ptr = ptr->next;
	if (ptr != NULL)
		is_flag(&ptr);
}

/*
@brief Set the type of elements in the list to EXEC.

@param list    The list of arguments.
*/
static void	type_exec(t_list **list)
{
	t_arg	*arg;

	arg = (*list)->content;
	if (arg->type == PIPE || arg->type == DELIM || arg->type == RI_FILE)
		return ;
	if (arg->type == TEXT)
		arg->type = EXEC;
	else
		*list = (*list)->next;
}

/*
@brief Set the type of elements in the list to ARG.

@param list    The list of arguments.
*/
static void	type_arg(t_list **list)
{
	t_arg	*arg;
	t_list	*ptr;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg->type == PIPE || delim_or_rifile(arg->type)
			|| r_or_p(arg->type))
			return ;
		if (arg->type == TEXT)
			arg->type = ARG;
		ptr = ptr->next;
	}
}

void	*define_elem(t_list **list)
{
	t_list	*ptr;

	ptr = *list;
	while (ptr != NULL && ((t_arg *)ptr->content)->type != EXEC
		&& !r_or_p(((t_arg *)ptr->content)->type)
		&& ((t_arg *)ptr->content)->type != DOLLAR)
		type_exec(&ptr);
	if (ptr != NULL && ((t_arg *)ptr->content)->type != FLAG
		&& !r_or_p(((t_arg *)ptr->content)->type)
		&& ((t_arg *)ptr->content)->type != DOLLAR)
		is_flag(&ptr);
	if (ptr != NULL && ((t_arg *)ptr->content)->type != ARG
		&& !r_or_p(((t_arg *)ptr->content)->type)
		&& ((t_arg *)ptr->content)->type != DOLLAR)
		type_arg(&ptr);
	while (ptr != NULL && ((t_arg *)ptr->content)->type != PIPE
		&& !delim_or_rifile(((t_arg *)ptr->content)->type))
		ptr = ptr->next;
	if (ptr != NULL && (((t_arg *)ptr->content)->type == PIPE
			|| delim_or_rifile(((t_arg *)ptr->content)->type)))
	{
		ptr = ptr->next;
		define_elem(&ptr);
	}
	return (0);
}
