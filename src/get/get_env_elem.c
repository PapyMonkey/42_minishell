/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:09:21 by aguiri            #+#    #+#             */
/*   Updated: 2023/02/25 16:42:20 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env_elem(t_list *const l_env, const char *env_key)
{
	t_list	*tmp_env;
	t_list	*tmp_env_next;
	int		key_len;

	tmp_env = l_env;
	key_len = ft_strlen(env_key);
	while (tmp_env)
	{
		if (!ft_strncmp(
				((t_env *)(tmp_env->content))->key,
				env_key,
				key_len)
			&& ft_strlen(((t_env *)(tmp_env->content))->key) == key_len)
			return (tmp_env);
		tmp_env_next = tmp_env->next;
		tmp_env = tmp_env_next;
	}
	return (NULL);
}
