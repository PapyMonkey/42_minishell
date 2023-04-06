/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:57:50 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 02:58:57 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_and_write_to_fd(
	int fd_read,
	int fd_write)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];

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

void	read_and_write_to_fd_heredoc(
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
