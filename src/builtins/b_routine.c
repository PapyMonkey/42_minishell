/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:59:51 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/06 06:02:41 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	b_routine(const char *str, t_var *var)
{
	int	len;

	len = ft_strlen(str);
	if (!ft_strncmp(str, "echo", 4) && ft_isspace(*(str + 4)))
		b_echo(str);
	else if (!ft_strncmp(str, "env", len))
		b_env(var->l_env);
	else if (!ft_strncmp(str, "pwd", len))
		b_pwd(var->l_env);
	else if (!ft_strncmp(str, "unset", 5) && ft_isspace(*(str + 5)))
		b_unset(var->l_env, str);
	else if (!ft_strncmp(str, "exit", 4)
		&& (len == 4 || ft_isspace(*(str + 4))))
		b_exit(var);
	else
		return (0);
	return (1);
}
