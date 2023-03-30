/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:51:05 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 06:12:57 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_table	*exp_construct(t_var *var)
{
	t_cmd_table	*table;
	t_list		*tmp;
	int			index;

	// table = malloc(sizeof(t_cmd_table *) * var->n_cmds + 1);
	table = malloc(sizeof(t_cmd_table) * var->n_cmds);
	if (!table)
		err_malloc_exit();
	// table[var->n_cmds] = '\0';
	index = 0;
	tmp = var->l_arg;
	while (tmp && index != var->n_cmds)
	{
		if (is_command(tmp))
		{
			table[index].cmd_ptr = tmp;
			table[index].cmd_str = exec_recreate_cmd(tmp);
			index++;
		}
		tmp = tmp->next;
	}
	return (table);
}
