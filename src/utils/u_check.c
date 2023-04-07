/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:53:34 by aguiri            #+#    #+#             */
/*   Updated: 2023/02/25 17:47:36 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exp_input(const char *str)
{
	if (ft_strchr(str, 39))
	{
		printf("export: \"%s\" not a valid identifier\n", str);
		return (EXIT_FAILURE);
	}
	if (*str == '=')
	{
		printf("export: \"%s\" not a valid identifier\n", str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
t_list	*check_env_exist(const t_var *var, const char *str)
{
	t_list	*tmp_env;
	t_list	*tmp_next;
	int		length;

	tmp_env = var->l_env;
	length = strlen_custom(str, '=');
	while (!tmp_env)
	{
		if (!ft_strncmp(
				(char *)(((t_env *)(tmp_env->content))->key),
				str,
				length
				))
			return (tmp_env);
		tmp_next = tmp_env->next;
		tmp_env = tmp_next;
	}
	return (NULL);
}
*/
