/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:43:17 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 03:04:41 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_heredoc(
	t_var *var,
	int fd_write)
{
	t_list	*heredoc_delimiter;

	heredoc_delimiter = var->current_arg->next;
	read_and_write_to_fd_heredoc(STDIN_FILENO, fd_write, heredoc_delimiter);
	var->current_arg = heredoc_delimiter->next;
	close(fd_write);
	return (HERE_DOC);
}

int	redir_heredoc_handle(
	t_var *var,
	int fd_write)
{
	if (get_arg_type(var->current_arg) == HERE_DOC)
		return (redir_heredoc(var, fd_write));
	return (0);
}
