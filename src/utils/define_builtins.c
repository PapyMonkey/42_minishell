/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:53 by bgales            #+#    #+#             */
/*   Updated: 2023/04/07 18:55:16 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(char *str)
{
	if (!str)
		return (0);
	if (!ft_strncmp(str, "echo", 4))
		return (1);
 	if (!ft_strncmp(str, "env", 3))
		return (1);
	if (!ft_strncmp(str, "pwd", 3))
		return (1);
	if (!ft_strncmp(str, "unset", 5))
		return (1);
	if (!ft_strncmp(str, "exit", 4))
		return (1);
	if (!ft_strncmp(str, "cd", 2))
		return (1);
	if (!ft_strncmp(str, "export", 6))
		return (1);

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