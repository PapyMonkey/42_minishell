/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:59:51 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/06 04:16:51 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	b_routine(const char *str, const t_var *var)
{
	int	len;

	len = ft_strlen(str);
	if (!ft_strncmp(str, "echo", 4) && *(str + 4) == ' ')
		b_echo(str);
	else if (!ft_strncmp(str, "env", len))
		b_env(var->l_env);
	else if (!ft_strncmp(str, "pwd", len))
		b_pwd(var->l_env);
	else
		return (0);
	return (1);
}
