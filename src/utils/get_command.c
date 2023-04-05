/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:51:05 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 00:08:37 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *get_command_next(t_list *l_arg)
{
	t_list *tmp;

	tmp = l_arg->next;
	while (tmp && !is_command(tmp))
		tmp = tmp->next;
	return(tmp);
}

t_list *get_command_or_redir_next(t_list *l_arg)
{
	t_list *tmp;

	tmp = l_arg->next;
	while (tmp
		&& !is_command(tmp)
		&& !is_redir_in(tmp)
		&& !is_redir_out(tmp))
		tmp = tmp->next;
	return(tmp);
}