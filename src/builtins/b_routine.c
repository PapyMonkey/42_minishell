/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:59:51 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/07 23:22:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_routine(t_var *var)
{
	char	*command;

	var->command_array= exec_build_cmd(var->cmd_current);
	command = get_arg_content(var->cmd_current);
	if (!ft_strncmp(command, "echo", 4))
		b_echo(var);
	else if (!ft_strncmp(command, "env", 3))
		b_env(var);
	else if (!ft_strncmp(command, "pwd", 3))
		b_pwd(var);
	else if (!ft_strncmp(command, "unset", 5))
		b_unset(var);
	else if (!ft_strncmp(command, "exit", 4))
		b_exit(var);
	else if (!ft_strncmp(command, "cd", 2))
		b_cd(var);
	else if (!ft_strncmp(command, "export", 6))
		b_export(var);
}
