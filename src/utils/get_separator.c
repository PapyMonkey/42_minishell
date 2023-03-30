/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:51:05 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 06:19:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *get_previous_sep(
	t_var *var,
	int	index)
{
	t_list *tmp;

	tmp = var->l_arg;
	while (tmp
		&& tmp != var->table_cmd[index].cmd_ptr
		&& !is_separator(tmp))
		tmp = tmp->next;
	if (tmp == var->table_cmd[index].cmd_ptr)
		return (NULL);
	return(tmp);
}
