/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:59:43 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/13 16:27:11 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: Documentation
static int	redir_out(t_var *var)
{
	t_list	*file_to_open;
	int		fd_output;

	file_to_open = var->next_redir_out->next;
	if (!file_to_open)
		err_exit("syntax error near unexpected token `newline`", NULL, 2);
	fd_output = open(get_arg_content(file_to_open),
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_output < 0)
		err_exit(get_arg_content(file_to_open), strerror(errno), errno);
	exec_redirect_fd(fd_output, STDOUT_FILENO);
	// ft_lstremove(&var->cmd_current, file_to_open, free_lstcontent);
	// ft_lstremove(&var->cmd_current, var->next_redir_out, free_lstcontent);
	var->next_redir_out = get_next_redir_out(var, var->next_redir_out->next);
	return (REDIR_OUT);
}

// NOTE: Documentation
static int	redir_append(t_var *var)
{
	t_list	*file_to_open;
	int		fd_output;

	file_to_open = var->next_redir_out->next;
	if (!file_to_open)
		err_exit("syntax error near unexpected token `newline`", NULL, 2);
	fd_output = open(get_arg_content(file_to_open),
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_output < 0)
		err_exit(get_arg_content(file_to_open), strerror(errno), errno);
	exec_redirect_fd(fd_output, STDOUT_FILENO);
	// ft_lstremove(&var->cmd_current, file_to_open, free_lstcontent);
	// ft_lstremove(&var->cmd_current, var->next_redir_out, free_lstcontent);
	var->next_redir_out = get_next_redir_out(var, var->next_redir_out->next);
	return (APPEND);
}

int	redir_out_handle(t_var *var)
{
	int	result_redirections_out;

	result_redirections_out = -1;
	while (var->next_redir_out && is_redir_out(var->next_redir_out))
	{
		if (get_arg_type(var->next_redir_out) == REDIR_OUT)
			result_redirections_out = redir_out(var);
		else if (get_arg_type(var->next_redir_out) == APPEND)
			result_redirections_out = redir_append(var);
	}
	return (result_redirections_out);
}
