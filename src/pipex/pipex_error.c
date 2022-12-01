/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:32:03 by aguiri            #+#    #+#             */
/*   Updated: 2022/05/31 16:36:11 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_put_exit(void)
{
	ft_printf("Error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	ft_error_put_exit_command_not_found(char *str)
{
	ft_printf("Error: command not found: %s\n", str);
	exit(EXIT_FAILURE);
}
