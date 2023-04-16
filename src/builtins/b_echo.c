/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:22:44 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 02:33:14 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Test if the input string contains a valid echo flag.

@param str    Input string to test for the echo flag.
@return       EXIT_SUCCESS if the input string contains a valid echo flag,
              EXIT_FAILURE otherwise.
*/
static int	b_echo_test_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (str[i] != 'n')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
@brief Echo command extension.

@param var     Variable structure.
@return             1 if return line should be printed, 0 otherwise.
*/
static int	b_echo_ext(t_var *const var)
{
	int		is_return_line;
	int		i;
	char	**cmd_array;
	t_list	*tmp;

	is_return_line = 1;
	i = 1;
	cmd_array = var->command_array;
	tmp = var->cmd_current->next;
	while (get_arg_type(tmp) == FLAG)
	{
		if (!b_echo_test_flag(var->command_array[i]))
		{
			is_return_line = 0;
			i++;
		}
		tmp = tmp->next;
	}
	while (cmd_array[i])
	{
		ft_putstr_fd(cmd_array[i], 1);
		if (cmd_array[++i])
			ft_putstr_fd(" ", 1);
	}
	return (is_return_line);
}

int	b_echo(t_var *const var)
{
	int	is_return_line;

	is_return_line = 1;
	if (var->cmd_current->next)
		is_return_line = b_echo_ext(var);
	if (is_return_line)
		ft_putstr_fd("\n", 1);
	g_process.return_code = 0;
	return (g_process.return_code);
}
