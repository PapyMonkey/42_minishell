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

char	*get_env_key(const t_list *l_env_element)
{
	return (((t_env *)l_env_element->content)->key);
}

char	*get_env_value(const t_list *l_env_element)
{
	return (((t_env *)l_env_element->content)->value);
}

t_list	*search_env_elem(t_list *const l_env, char *const env_key)
{
	int		env_key_len;
	t_list	*tmp_env;

	env_key_len = ft_strlen(env_key);
	tmp_env = l_env;
	while (
		!(!ft_strncmp(get_env_key(tmp_env), env_key, env_key_len)
		&& ft_strlen(get_env_key(tmp_env)) == env_key_len)
		&& tmp_env->next != NULL
	)
		tmp_env = tmp_env->next;
	if (
		ft_strncmp(get_env_key(tmp_env), env_key, env_key_len)
		&& tmp_env->next == NULL
	)
		return (NULL);
	return (tmp_env);
}
