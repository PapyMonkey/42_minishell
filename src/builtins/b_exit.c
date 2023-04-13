/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:55:53 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/13 16:26:44 by aguiri           ###   ########.fr       */
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

	argument_number = count_argument(var->cmd_current);
	if (argument_number > 1)
		return (err_d("exit", var->command_array[argument_number - 1],
			"invalid option", 2));
	g_process.return_code = 0;
	effective_exit(var);
}
