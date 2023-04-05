/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:09:36 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/05 21:49:12 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err_malloc_exit(void)
{
	ft_printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void	err_put_exit(void)
{
	ft_printf("Error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	err_put_exit_command_not_found(char *str)
{
	ft_printf("Error: command not found: %s\n", str);
	exit(EXIT_FAILURE);
}

void err_put_exit_wrong_fd(void)
{
	ft_printf("Error: fd allocation failed\n");
	exit(EXIT_FAILURE);
}
