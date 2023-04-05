/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:43:17 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 00:47:19 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void print_current_cmd(t_var *var)
{
	if (!var->current_arg)
		printf("current cmd : NULL\n");
	else
		printf("current cmd : %s\n", get_arg_content(var->current_arg));
}

static void read_and_write_to_fd(
	int fd_read,
	int fd_write)
{
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    bytes_read = read(fd_read, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        if (write(fd_write, buffer, bytes_read) != bytes_read)
			err_put_exit();
        bytes_read = read(fd_read, buffer, BUFFER_SIZE);
    }
    if (bytes_read < 0)
		err_put_exit();
}

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
	// exec_redirect_fd(fd_write, STDIN_FILENO);
	var->current_arg = file_to_open->next;
	close(fd_read);
	close(fd_write);
	return (REDIR_IN);
}

static int redir_out(
	t_var *var,
	int fd_read)
{
	t_list *file_to_open;
	int		fd_write;

	file_to_open = var->current_arg->next;
	fd_write = open(get_arg_content(file_to_open),
		   O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_write < 0)
		err_put_exit();
	read_and_write_to_fd(fd_read, fd_write);
	// exec_redirect_fd(fd_out, STDOUT_FILENO);
	var->current_arg = file_to_open->next;
	close(fd_read);
	close(fd_write);
	return (REDIR_OUT);
}

static int redir_append(
	t_var *var,
	int fd_read)
{
	t_list *file_to_open;
	int		fd_write;

	file_to_open = var->current_arg->next;
	fd_write = open(get_arg_content(file_to_open),
		   O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_write < 0)
		err_put_exit();
	read_and_write_to_fd(fd_read, fd_write);
	// exec_redirect_fd(fd, STDOUT_FILENO);
	var->current_arg = file_to_open->next;
	close(fd_read);
	close(fd_write);
	return (APPEND);
}

int redir_in_handle(
	t_var *var,
	int fd_write)
{
	printf("Check redir_in - ");
	print_current_cmd(var);
	if (get_arg_type(var->current_arg) == REDIR_IN)
		return (redir_in(var, fd_write));
	return (0);
}

int redir_out_handle(
	t_var *var,
	int fd_read)
{
	printf("Check redir_out - ");
	print_current_cmd(var);
	if (get_arg_type(var->current_arg) == REDIR_OUT)
		return (redir_out(var, fd_read));
	else if (get_arg_type(var->current_arg) == APPEND)
		return (redir_append(var, fd_read));
	return (0);
}
