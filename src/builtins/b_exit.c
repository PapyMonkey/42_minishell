/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:55:53 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 05:58:03 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// FIX: Change the flag error to a general argument error
// TODO: change :
//	- to implement a wrapper for exit
//	- to implement possible flags
//	- to implement error code when called with arguments
void	b_exit(t_var *var)
{
	t_list	*flag;

	flag = check_arg_flag(var->current_arg);
	if (flag)
	{
		err_d("exit", get_arg_content(flag), "invalid option", 2);
		return ;
	}
	free_var(var);
	ft_putstr_fd("exit\n", 1);
	g_process.return_code = 0;
	exit (EXIT_SUCCESS);
}
