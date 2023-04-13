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

int	err(
	char *err,
	char *info,
	int code)
{
	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	if (info)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(info, 2);
	}
	ft_putstr_fd("\n", 2);
	g_process.return_code = code;
	return (code);
}

int	err_d(
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
	return (code);
}

void	err_exit(
	char *error,
	char *info,
	int code)
{
	err(error, info, code);
	exit(g_process.return_code);
}
