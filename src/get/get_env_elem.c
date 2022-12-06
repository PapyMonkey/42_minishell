/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:09:21 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 04:58:59 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env_elem(t_list *const l_env, const char *env_key)
{
	int		env_key_len;
	t_list	*tmp_env;
	t_list	*tmp_env_next;

	env_key_len = ft_strlen(env_key);
	tmp_env = l_env;
	while (
		!(!ft_strncmp(((t_env *)(tmp_env->content))->key, env_key, env_key_len)
		&& ft_strlen(((t_env *)(tmp_env->content))->key) == env_key_len)
		&& tmp_env->next != NULL
	)
	{
		tmp_env_next = tmp_env->next;
		tmp_env = tmp_env_next;
	}
	if (
		!ft_strncmp(((t_env *)(tmp_env->content))->key, env_key, env_key_len)
		&& tmp_env->next == NULL
	)
		return (NULL);
	return (tmp_env);
}
