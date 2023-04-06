/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:59:43 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 02:59:49 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_out(
	t_var *var,
	int fd_read)
{
	t_list	*file_to_open;
	int		fd_write;

	file_to_open = var->current_arg->next;
	fd_write = open(get_arg_content(file_to_open),
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_write < 0)
		err_put_exit();
	read_and_write_to_fd(fd_read, fd_write);
	var->current_arg = file_to_open->next;
	close(fd_read);
	close(fd_write);
	return (REDIR_OUT);
}

static int	redir_append(
	t_var *var,
	int fd_read)
{
	t_list	*file_to_open;
	int		fd_write;

	file_to_open = var->current_arg->next;
	fd_write = open(get_arg_content(file_to_open),
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_write < 0)
		err_put_exit();
	read_and_write_to_fd(fd_read, fd_write);
	var->current_arg = file_to_open->next;
	close(fd_read);
	close(fd_write);
	return (APPEND);
}

int	redir_out_handle(
	t_var *var,
	int fd_read)
{
	if (get_arg_type(var->current_arg) == REDIR_OUT)
		return (redir_out(var, fd_read));
	else if (get_arg_type(var->current_arg) == APPEND)
		return (redir_append(var, fd_read));
	return (0);
}
