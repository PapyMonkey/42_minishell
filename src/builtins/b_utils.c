/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:59:51 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/30 16:41:58 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	b_routine(const char *str, const char **envp)
{
	int	len;

	len = ft_strlen(str);
	if (!ft_strncmp(str, "echo", 4) && *(str + 4) == ' ')
		b_echo(str);
	else if (!ft_strncmp(str, "env", len))
		b_env(envp);
	else if (!ft_strncmp(str, "pwd", len))
		b_pwd(envp);
	else
		return (0);
	return (1);
}
