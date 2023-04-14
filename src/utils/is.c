/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:51:05 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 01:55:09 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "structures.h"

int	is_command(t_list *l_arg)
{
	t_enum_type	type;

	type = get_arg_type(l_arg);
	if (type == EXEC || type == BUILTIN)
		return (1);
	else
		return (0);
}

int	is_redir_and_tokens(t_list *l_arg)
{
	t_enum_type	type;

	type = get_arg_type(l_arg);
	if (is_redir_in(l_arg)
		|| is_redir_in(l_arg)
		|| type == R_FILE
		|| type == RI_FILE
		|| type == DELIM)
		return (1);
	else
		return (0);
}

int	is_redir_in(t_list *l_arg)
{
	t_enum_type	type;

	type = get_arg_type(l_arg);
	if (type == REDIR_IN
		|| type == HERE_DOC)
		return (1);
	else
		return (0);
}

int	is_redir_out(t_list *l_arg)
{
	t_enum_type	type;

	type = get_arg_type(l_arg);
	if (type == REDIR_OUT
		|| type == APPEND)
		return (1);
	else
		return (0);
}

int	is_separator(t_list *l_arg)
{
	t_enum_type	type;

	type = get_arg_type(l_arg);
	if (type == PIPE
		|| type == APPEND
		|| type == REDIR_IN
		|| type == REDIR_OUT
		|| type == HERE_DOC
	)
		return (1);
	else
		return (0);
}
