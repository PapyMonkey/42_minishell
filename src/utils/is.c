/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:51:05 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:27:52 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_command(t_list *l_arg)
{
	t_enum_type	type;

	type = get_arg_type(l_arg);
	if (type == EXEC || type == BUILTIN)
		return(1);
	else
		return(0);
}

int	is_separator(t_list *l_arg)
{
	t_enum_type	type;

	type = get_arg_type(l_arg);
	if (
		// TODO: Implement semicolon (SEMICOLON) check
		type == PIPE
		|| type == APPEND
		|| type == REDIR_IN
		|| type == REDIR_OUT
		|| type == HERE_DOC
		)
		return(1);
	else
		return(0);
}
