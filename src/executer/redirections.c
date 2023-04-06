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

static void read_and_write_to_fd_heredoc(
	int fd_read,
	int fd_write,
	const t_list *heredoc_delimiter)
{
    ssize_t	bytes_read;
    char	buffer[BUFFER_SIZE];
	char	*delimiter_str;
	// int		delimiter_length;
	char	*search_str;
	char	*str_to_write;

    bytes_read = read(fd_read, buffer, BUFFER_SIZE);
	delimiter_str = get_arg_content(heredoc_delimiter);
	// delimiter_length = ft_strlen(delimiter_str);
	search_str = ft_strnstr(buffer, delimiter_str, BUFFER_SIZE);
    while (bytes_read > 0 && (!search_str || search_str == buffer))
    {
		if (!search_str)
			str_to_write = buffer;
		else 
			str_to_write = search_str;
        if (write(fd_write, buffer, bytes_read - ft_strlen(search_str))
			!= bytes_read - ft_strlen(search_str))
			err_put_exit();
		// TODO: Recuperer l'excedent (apres le delimiter) pour le stocker,
		// parser et ajouter la liste des commandes a executer
        bytes_read = read(fd_read, buffer, BUFFER_SIZE);
    }
    if (bytes_read < 0)
		err_put_exit();
}

static void read_and_write_to_fd_heredoc_v2(
	int fd_read,
	int fd_write,
	const t_list *heredoc_delimiter)
{
	char	*out;
	char	*delimiter_str;
	int		delimiter_length;

	out = ft_get_next_line(fd_read);
	delimiter_str = get_arg_content(heredoc_delimiter);
	delimiter_length = ft_strlen(delimiter_str);
	if (!out)
		err_put_exit();
	while (ft_strncmp(out, delimiter_str, delimiter_length))
	{
		if (write(fd_write, out, ft_strlen(out)) == -1)
			err_put_exit();
		out = ft_get_next_line(fd_read);
		// TODO: Recuperer l'excedent (apres le delimiter) pour le stocker,
		// parser et ajouter la liste des commandes a executer
	}
	free(out);
	close(fd_write);
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

static int redir_heredoc(
	t_var *var,
	int fd_write)
{
	t_list *heredoc_delimiter;

	heredoc_delimiter = var->current_arg->next;
	read_and_write_to_fd_heredoc_v2(STDIN_FILENO, fd_write, heredoc_delimiter);
	var->current_arg = heredoc_delimiter->next;
	close(fd_write);
	return (HERE_DOC);
}

int redir_heredoc_handle(
	t_var *var,
	int fd_write)
{
	if (get_arg_type(var->current_arg) == HERE_DOC)
		return (redir_heredoc(var, fd_write));
	return (0);
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
	var->current_arg = file_to_open->next;
	close(fd_read);
	close(fd_write);
	return (APPEND);
}

int redir_out_handle(
	t_var *var,
	int fd_read)
{
	if (get_arg_type(var->current_arg) == REDIR_OUT)
		return (redir_out(var, fd_read));
	else if (get_arg_type(var->current_arg) == APPEND)
		return (redir_append(var, fd_read));
	return (0);
}
