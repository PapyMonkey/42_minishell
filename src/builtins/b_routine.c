/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:59:51 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/07 23:22:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// FIX: Make an error command to print "<command> takes no flag (<flag>)"
// FIX: Find a way to get the ENV updated in every process
void	b_routine(t_var *var)
{
	char	*command;

	command = get_arg_content(var->current_arg);
	if (!ft_strncmp(command, "echo", 4))
		b_echo(var);
	else if (!ft_strncmp(command, "env", 3))
		b_env(var->l_env);
	else if (!ft_strncmp(command, "pwd", 3))
		b_pwd(var->l_env);
	else if (!ft_strncmp(command, "unset", 5))
		b_unset(var);
	else if (!ft_strncmp(command, "exit", 4))
		b_exit(var);
	// else if (!ft_strncmp(str, "cd", 2) && ft_isspace(*(str + 2)))
	// 	b_cd(&var->l_env, (char *)str + 2);
}
