/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:07 by bgales            #+#    #+#             */
/*   Updated: 2023/04/06 17:55:36 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Check if the type is a redirection.

@param type    The argument type to check.
@return        Returns 1 if the type is a redirection, 0 otherwise.
*/
static int	arg_is_redir(int type)
{
	if (type == REDIR_IN || type == HERE_DOC || type == DELIM
		|| type == REDIR_OUT || type == APPEND)
		return (1);
	return (0);
}

int	r_or_p(int type)
{
	if (type == REDIR_IN || type == HERE_DOC || type == DELIM
		|| type == REDIR_OUT || type == APPEND || type == PIPE)
		return (1);
	return (0);
}

int	delim_or_rifile(int type)
{
	if (type == RI_FILE || type == DELIM)
		return (1);
	return (0);
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
			if (arg->type == HERE_DOC)
			{
				ptr = ptr->next;
				if (ptr == NULL)
					return ;
				arg = ptr->content;
				if (!r_or_p(arg->type))
					arg->type = DELIM;
			}
			else
				define_redir_ext(&ptr->next);
			arg = ptr->content;
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}
