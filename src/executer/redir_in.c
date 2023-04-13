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

static int	redir_in(t_var *var)
{
	t_list	*file_to_open;
	int		fd_input;

	file_to_open = var->current_arg->next;
	if (!file_to_open)
		err_exit("syntax error near unexpected token `newline`", NULL, 2);
	printf("file_to_open=%s\n", get_arg_content(file_to_open));
	fd_input = open(get_arg_content(file_to_open),
			O_RDONLY);
	if (fd_input < 0)
		err_exit(get_arg_content(file_to_open), strerror(errno), errno);
	exec_redirect_fd(fd_input, STDIN_FILENO);
	var->current_arg = get_command_or_redir_next(var->current_arg);
	return (REDIR_IN);
}

// FIX: Change the way heredoc works, broken for now
static int	redir_heredoc(t_var *var)
{
	t_list	*heredoc_delimiter;

	// heredoc_delimiter = var->current_arg->next;
	// read_and_write_to_fd_heredoc(STDIN_FILENO, fd_write, heredoc_delimiter);
	// var->current_arg = heredoc_delimiter->next;
	// close(fd_write);
	return (HERE_DOC);
}

int	redir_in_handle(t_var *var)
{
	if (get_arg_type(var->current_arg) == REDIR_IN)
		return (redir_in(var));
	else if (get_arg_type(var->current_arg) == HERE_DOC)
		return (redir_heredoc(var));
	return (-1);
}
