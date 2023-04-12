/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:22:44 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/07 23:23:15 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	b_echo_ext(t_var *const var)
{
	int		is_return_line;
	int		i;
	char	**cmd_array;

	is_return_line = 1;
	i = 1;
	cmd_array = var->command_array;
	if (get_arg_type(var->current_arg->next) == FLAG
		&& !ft_strncmp(var->command_array[i], "-n",
			ft_strlen(cmd_array[i])))
	{
		is_return_line = 0;
		i++;
	}
	while (cmd_array[i])
	{
		ft_putstr_fd(cmd_array[i], 1);
		if (cmd_array[++i])
			ft_putstr_fd(" ", 1);
	}
	return (is_return_line);
}

// FIX: differents usecases
// - [X] No argument should print \n
// - [X] Check flags, if any (except -n) -> errors
//		- Only check the first flags, rest is treated as text
// - [X] Flag -n should be first argument, otherwise treated as text
void	b_echo(t_var *const var)
{
	int	is_return_line;

	if (var->current_arg->next)
		is_return_line = b_echo_ext(var);
	if (is_return_line)
		ft_putstr_fd("\n", 1);
	g_process.return_code = 0;
}
