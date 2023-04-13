/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:51:05 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/13 16:12:18 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_cmd_start(t_var *var)
{
	t_list	*tmp;

	if (!var->l_arg)
		return (NULL);
	tmp = var->cmd_end;
	while (
		tmp
		&& !is_command(tmp)
		&& !is_redir_in(tmp))
		tmp = tmp->next;
	return (tmp);
}

t_list	*get_cmd_end(
	t_var *var,
	t_list *const start)
{
	t_list	*tmp;

	if (!start)
		return (NULL);
	tmp = start;
	while (
		tmp
		&& get_arg_type(tmp) != PIPE)
		tmp = tmp->next;
	return (tmp);
}

t_list	*get_cmd_current(
	t_var *var,
	t_list *const start)
{
	t_list	*tmp;

	if (!start)
		return (NULL);
	tmp = start;
	while (
		tmp
		&& tmp != var->cmd_end
		&& !is_command(tmp))
		tmp = tmp->next;
	return (tmp);
}

t_list	*get_next_redir_in(
	t_var *var,
	t_list *const start)
{
	t_list	*tmp;

	if (!start)
		return (NULL);
	tmp = start;
	while (
		tmp
		&& tmp != var->cmd_end
		&& !is_redir_in(tmp))
		tmp = tmp->next;
	return (tmp);
}

t_list	*get_next_redir_out(
	t_var *var,
	t_list *const start)
{
	t_list	*tmp;

	if (!start)
		return (NULL);
	tmp = start;
	while (
		tmp
		&& tmp != var->cmd_end
		&& !is_redir_out(tmp))
		tmp = tmp->next;
	return (tmp);
}
