/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:09:36 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/05 23:05:04 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err(
	char *err,
	char *info,
	int code)
{
	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(info, 2);
	ft_putstr_fd("\n", 2);
	g_process.return_code = code;
}

void	err_d(
	char *err,
	char *info,
	char *info_2,
	int code)
{
	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(info, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(info_2, 2);
	ft_putstr_fd("\n", 2);
	g_process.return_code = code;
}

void	err_custom_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

// HACK: change the way we display errors
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
