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

// NOTE: Documentation
static int	redir_out(t_var *var)
{
	t_list	*file_to_open;
	int		fd_output;

	file_to_open = var->next_redir_out->next;
	fd_output = open(get_arg_content(file_to_open),
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_output < 0)
		err("", strerror(errno), errno);
	exec_redirect_fd(fd_output, STDOUT_FILENO);
	ft_lstremove(&var->current_arg, file_to_open, free_lstcontent);
	ft_lstremove(&var->current_arg, var->next_redir_out, free_lstcontent);
	return (REDIR_OUT);
}

// NOTE: Documentation
static int	redir_append(t_var *var)
{
	t_list	*file_to_open;
	int		fd_output;

	file_to_open = var->next_redir_out->next;
	printf("file_to_open (append) : %s\n", get_arg_content(file_to_open));
	fd_output = open(get_arg_content(file_to_open),
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_output < 0)
		err("", strerror(errno), errno);
	exec_redirect_fd(fd_output, STDOUT_FILENO);
	ft_lstremove(&var->current_arg, file_to_open, free_lstcontent);
	ft_lstremove(&var->current_arg, var->next_redir_out, free_lstcontent);
	return (APPEND);
}

int	redir_out_handle(t_var *var)
{
	if (get_arg_type(var->next_redir_out) == REDIR_OUT)
		return (redir_out(var));
	else if (get_arg_type(var->next_redir_out) == APPEND)
		return (redir_append(var));
	return (-1);
}
