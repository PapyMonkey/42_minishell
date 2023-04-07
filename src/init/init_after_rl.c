/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_after_rl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:25:20 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/07 22:55:54 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int init_command_context(
	t_var *var,
	char *const input)
{
	int		fd[2];

	var->l_arg = ft_split_args(input, var->l_env);
	var->current_arg = var->l_arg;
	var->n_cmds = count_command(var->l_arg);
	var->n_redirs = count_redirections(var->l_arg);
	if (pipe(fd) == -1)
		err_put_exit();
	close(fd[WRITE_END]);
	return (fd[READ_END]);
}
