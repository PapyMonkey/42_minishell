/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:30:37 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 17:40:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(t_var *var)
{
	t_list	*tmp;
	char	**out;

	while (!ft_strncmp(((t_env *)var->l_env)->key, "PATH", 4))
	{
		tmp = var->l_env->next;
		var->l_env = tmp;
	}
	if (!((t_env *)var->l_env)->value)
		return (NULL);
	return (ft_split(((t_env *)var->l_env)->value, ':'));
}
