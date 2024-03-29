/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:57:36 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/18 13:50:09 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_free(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_command_context(
	t_var *var,
	char *input,
	int fd_read_end)
{
	close(fd_read_end);
	safe_free(input);
	safe_free(var->command_array);
	var->command_array = NULL;
	ft_lstclear(&var->l_arg, free_lstcontent);
}

void	free_env(void *env)
{
	safe_free(((t_env *)env)->key);
	safe_free(((t_env *)env)->value);
	safe_free(env);
}

void	free_var(struct s_var *var)
{
	ft_lstclear(&var->l_arg, free_lstcontent);
	ft_lstclear(&var->l_env, free_env);
	ft_lstclear(&var->l_exp, free);
	safe_free(var->command_array);
	safe_free(var);
}

void	free_2d_char(char **array)
{
	int	i;

	i = 0;
	while (!array && array[i])
		safe_free(array[i++]);
	safe_free(array);
}
