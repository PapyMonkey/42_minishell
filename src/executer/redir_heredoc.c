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
<<<<<<<< HEAD:src/executer/redir_heredoc.c
	int fd_write)
{
	t_list	*heredoc_delimiter;
========
	int	index,
	int fd_old,
	int fd_new)
{
	t_list	*previous_separator;
>>>>>>>> 66e9bad (chore: WIP):src/executer/setup_fd.bak

	heredoc_delimiter = var->current_arg->next;
	read_and_write_to_fd_heredoc(STDIN_FILENO, fd_write, heredoc_delimiter);
	var->current_arg = heredoc_delimiter->next;
	close(fd_write);
	return (HERE_DOC);
}

<<<<<<<< HEAD:src/executer/redir_heredoc.c
int	redir_heredoc_handle(
	t_var *var,
	int fd_write)
{
	if (get_arg_type(var->current_arg) == HERE_DOC)
		return (redir_heredoc(var, fd_write));
	return (0);
========
	}
>>>>>>>> 66e9bad (chore: WIP):src/executer/setup_fd.bak
}
