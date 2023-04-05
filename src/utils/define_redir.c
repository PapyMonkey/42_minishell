/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:07:07 by bgales            #+#    #+#             */
/*   Updated: 2023/04/05 14:28:58 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_is_redir(int type)
{
	if (type == REDIR_IN || type == HERE_DOC || type == DELIM
		|| type == REDIR_OUT || type == APPEND)
		return (1);
	return (0);
}

int	r_or_p(int type)
{
	if (type == REDIR_IN || type == HERE_DOC || type == DELIM
		|| type == REDIR_OUT || type == APPEND || type == PIPE
		|| type == RI_FILE)
		return (1);
	return (0);
}

int	delim_or_rifile(int type)
{
	if (type == RI_FILE || type == DELIM)
		return (1);
	return (0);
}

void	define_redir_2(t_list **list)
{
	t_arg	*arg;
	t_list	*ptr;

	ptr = *list;
	if (!ptr)
		return ;
	arg = ptr->content;
	if (arg->type == REDIR_OUT || arg->type == APPEND)
	{
		while (ptr != NULL)
		{
			arg = ptr->content;
			if (r_or_p(arg->type))
				break ;
			ptr = ptr->next;
			arg->type = R_FILE;
		}
	}
	else
	{
		arg = ptr->content;
		if (r_or_p(arg->type))
			return ;
		arg->type = RI_FILE;
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
				define_redir_2(&ptr->next);
			arg = ptr->content;
		}
		if (ptr != NULL)
			ptr = ptr->next;
	}
}
