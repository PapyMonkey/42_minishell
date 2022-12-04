/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:27:17 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 17:52:23 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
@brief Creates a new t_env element, splitting the provided *char on the first
		'=' character. Stores the output in a {key:value} pair.

@param envp One element of the 2D array storing all the ENV variables.
*/
static struct s_env	*init_env_element(char *envp)
{
	t_env	*element;
	int		envp_len;
	int		envp_pos_sep;

	element = malloc(sizeof(t_env));
	if (!element)
		err_malloc_exit();
	envp_len = ft_strlen(envp);
	envp_pos_sep = 0;
	while (envp[envp_pos_sep] != '=')
		envp_pos_sep++;
	element->key = ft_substr(envp, 0, envp_pos_sep);
	if (!element->key)
		err_malloc_exit();
	element->value = ft_substr(envp, envp_pos_sep + 1, envp_len);
	if (!element->value)
		err_malloc_exit();
	return (element);
}

void	init_env(t_var *var, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		ft_lstadd_back(
			&var->l_env,
			ft_lstnew(init_env_element(envp[i]))
			);
	}
}
