/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redir_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:21 by bgales            #+#    #+#             */
/*   Updated: 2023/04/13 11:25:23 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Check if the type is a redirection.

@param type    The argument type to check.
@return        Returns 1 if the type is a redirection, 0 otherwise.
*/

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
