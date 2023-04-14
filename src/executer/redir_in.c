/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:54:21 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 02:19:03 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_in(t_var *var)
{
	t_list	*file_to_open;
	int		fd_input;

	file_to_open = var->next_redir_in->next;
	if (!file_to_open)
	{
		err("syntax error near unexpected token `newline`", NULL, 2);
		return (EXIT_CODE);
	}
	fd_input = open(get_arg_content(file_to_open),
			O_RDONLY);
	if (fd_input < 0)
	{
		err(get_arg_content(file_to_open), strerror(errno), errno);
		return (EXIT_CODE);
	}
	exec_redirect_fd(fd_input, STDIN_FILENO);
	var->next_redir_in = get_next_redir_in(var, var->next_redir_in->next);
	return (REDIR_IN);
}

int	redir_in_handle(t_var *var)
{
	int	result_redirections_in;

	result_redirections_in = -1;
	while (var->next_redir_in && is_redir_in(var->next_redir_in))
	{
		if (get_arg_type(var->next_redir_in) == REDIR_IN)
		{
			result_redirections_in = redir_in(var);
			if (result_redirections_in == EXIT_CODE)
				return (EXIT_CODE);
		}
		else if (get_arg_type(var->next_redir_in) == HERE_DOC)
		{
			result_redirections_in = redir_heredoc(var);
			if (result_redirections_in == EXIT_CODE)
				return (EXIT_CODE);
		}
	}
	return (result_redirections_in);
}
