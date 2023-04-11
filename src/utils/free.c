/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:57:36 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/07 22:52:06 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command_context(
	t_var *var,
	char *input,
	int fd_read_end)
{
	close(fd_read_end);
	free(input);
	ft_lstclear(&var->l_arg, free_lstcontent);
}

void	free_env(void *env)
{
	free(((t_env *)env)->key);
	free(((t_env *)env)->value);
	free(env);
}

void	free_var(struct s_var *var)
{
	ft_lstclear(&var->l_arg, free_lstcontent);
	ft_lstclear(&var->l_env, free_env);
	ft_lstclear(&var->l_exp, free);
	free(var->command_array);
	free(var);
}

void	free_2d_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
