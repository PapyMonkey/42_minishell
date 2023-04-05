/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:51:05 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:30:53 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *get_command_next(t_list *l_arg)
{
	t_list *tmp;

	tmp = l_arg->next;
	while (tmp && !is_command(tmp->content))
		tmp = tmp->next;
	return(tmp);
}
