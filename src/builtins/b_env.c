/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:21:38 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/13 16:27:17 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_env(t_var *const var)
{
	int	argument_number;
	t_list	*tmp;

	argument_number = count_argument(var->cmd_current);
	if (argument_number > 1)
		return (err_d("env", var->command_array[argument_number - 1],
			"invalid option", 125));
	tmp = var->l_env;
	ft_lstiter(tmp, print_env_elem);
	g_process.return_code = 0;
}
