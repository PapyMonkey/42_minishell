/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:55:53 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 01:52:55 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	effective_exit(t_var *var)
{
	free_var(var);
	write(1, "exit\n", 5);
	exit(g_process.return_code);
}

int	b_exit(t_var *var)
{
	int	argument_number;
	int	i;

	argument_number = count_argument(var->cmd_current);
	if (argument_number > 2)
		return (err("exit", "too many arguments", 1));
	i = 0;
	while (argument_number == 2 && var->command_array[1][++i])
	{
		if (!ft_isdigit(var->command_array[1][i]))
			return (err("exit", "numeric argument required", 255));
	}
	if (argument_number == 2)
		g_process.return_code = ft_atoi(var->command_array[1]) % MODULO_EXIT;
	else
		g_process.return_code = 0;
	return (effective_exit(var));
}
