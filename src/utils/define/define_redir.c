/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:07 by bgales            #+#    #+#             */
/*   Updated: 2023/04/14 14:18:16 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	define_redir_in(t_list **list)
{
	t_arg	*arg;
	t_list	*ptr;

	ptr = *list;
	if (!ptr)
		return ;
	arg = ptr->content;
	arg->type = RI_FILE;
}

/*
@brief Define the type of elements related to redirection in the list.

@param list    The list of arguments.
*/
static void	define_redir_ext(t_list **list)
{
	t_arg	*arg;
	t_list	*ptr;

	ptr = *list;
	if (!ptr)
		return ;
	arg = ptr->content;
	arg->type = R_FILE;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (r_or_p(arg->type))
			break ;
		arg->type = ARG;
		ptr = ptr->next;
	}
}

/*
@brief Handle HERE_DOC redirections for the given list.

@param ptr      Pointer to the list element.
*/
static void	handle_here_doc(t_list **ptr)
{
	t_arg	*arg;

	*ptr = (*ptr)->next;
	if (*ptr == NULL)
		return ;
	arg = (*ptr)->content;
	if (!r_or_p(arg->type))
		arg->type = DELIM;
}

/*
@brief Handle different types of redirections for the given list.

@param ptr      Pointer to the list element.
*/
static void	handle_redirections(t_list **ptr)
{
	t_arg	*arg;

	arg = (*ptr)->content;
	if (arg->type == HERE_DOC)
		handle_here_doc(ptr);
	else if (arg->type == REDIR_IN)
		define_redir_in(&(*ptr)->next);
	else
		define_redir_ext(&(*ptr)->next);
}

void	define_redir(t_list **list)
{
	t_list	*ptr;
	t_arg	*arg;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg_is_redir(arg->type))
		{
			handle_redirections(&ptr);
			if (ptr == NULL)
				break ;
			arg = ptr->content;
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}
