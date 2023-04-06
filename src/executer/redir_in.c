/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:54:21 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 02:54:42 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int redir_in(
	t_var *var,
	int fd_write)
{
	t_list *file_to_open;
	int		fd_read;

	file_to_open = var->current_arg->next;
	fd_read = open(get_arg_content(file_to_open),
			O_RDONLY);
	if (fd_read < 0)
		err_put_exit();
	read_and_write_to_fd(fd_read, fd_write);
	var->current_arg = file_to_open->next;
	close(fd_read);
	close(fd_write);
	return (REDIR_IN);
}

int redir_in_handle(
	t_var *var,
	int fd_write)
{
	if (get_arg_type(var->current_arg) == REDIR_IN)
		return (redir_in(var, fd_write));
	return (0);
}

