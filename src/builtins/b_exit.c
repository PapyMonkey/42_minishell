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

// TODO: change :
//	- to implement a wrapper for exit
//	- to implement possible flags
//	- to implement error code when called with arguments
void	b_exit(t_var *var)
{
	free_var(var);
	ft_putstr_fd("exit\n", 1);
	exit (EXIT_SUCCESS);
}
