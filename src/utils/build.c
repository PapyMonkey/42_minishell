/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:43:56 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/13 15:57:18 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_cmd_ptrs(
	t_var *var,
	t_list *const start)
{
	var->cmd_start = start;
	var->cmd_end = get_cmd_end(start);
	var->cmd_current = get_cmd_current(var, start);
	var->next_redir_in = get_next_redir_in(var, start);
	var->next_redir_out = get_next_redir_out(var, start);
}
