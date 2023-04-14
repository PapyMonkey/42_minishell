/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:53 by bgales            #+#    #+#             */
/*   Updated: 2023/04/14 02:48:40 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Determine if a given string is a builtin command.

@param str    The string to check.
@return             1 if the string is a builtin command, 0 otherwise.
*/
static int	is_builtin(char *str)
{
	if (!str)
		return (0);
	else if ((!ft_strncmp(str, "echo", 4) && ft_strlen(str) == 4)
		|| (!ft_strncmp(str, "env", 3) && ft_strlen(str) == 3)
		|| (!ft_strncmp(str, "pwd", 3) && ft_strlen(str) == 3)
		|| (!ft_strncmp(str, "unset", 5) && ft_strlen(str) == 5)
		|| (!ft_strncmp(str, "exit", 4) && ft_strlen(str) == 4)
		|| (!ft_strncmp(str, "cd", 2) && ft_strlen(str) == 2)
		|| (!ft_strncmp(str, "export", 6) && ft_strlen(str) == 6))
		return (1);
	else
		return (0);
}

void	define_builtins(t_list **list)
{
	t_list	*ptr;
	t_arg	*arg;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (is_builtin(arg->content))
			arg->type = BUILTIN;
		ptr = ptr->next;
	}
}
