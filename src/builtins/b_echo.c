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

void	b_echo(const t_var *var)
{
	char	**cmd_array;
	int		is_flag;
	int		i;

	cmd_array = var->command_array;
	is_flag = 0;
	i = 1;
	if (!cmd_array[i])
		return ;
	if (get_arg_type(var->current_arg->next) == FLAG
		&& !ft_strncmp(var->command_array[i], "-n", ft_strlen(cmd_array[i])))
	{
		is_flag++;
		i++;
	}
	while (cmd_array[i])
	{
		printf("%s", cmd_array[i++]);
		if (cmd_array[i])
			printf(" ");
	}
	if (is_flag)
		printf("\n");
}
