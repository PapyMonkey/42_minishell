/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:59:51 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/14 01:51:03 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	b_routine(t_var *var)
{
	char	*command;

	var->command_array = exec_build_cmd(var->cmd_current);
	command = get_arg_content(var->cmd_current);
	if (!ft_strncmp(command, "echo", 4))
		return (b_echo(var));
	else if (!ft_strncmp(command, "env", 3))
		return (b_env(var));
	else if (!ft_strncmp(command, "pwd", 3))
		return (b_pwd(var));
	else if (!ft_strncmp(command, "unset", 5))
		return (b_unset(var));
	else if (!ft_strncmp(command, "exit", 4))
		return (b_exit(var));
	else if (!ft_strncmp(command, "cd", 2))
		return (b_cd(var));
	else if (!ft_strncmp(command, "export", 6))
		return (b_export(var));
	return (EXIT_SUCCESS);
}
