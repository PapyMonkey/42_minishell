/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:30:37 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 04:05:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(const t_list *l_env)
{
	t_list	*tmp;

	tmp = get_env_elem(l_env, "PATH");
	if (!tmp)
		return (NULL);
	return (ft_split(((t_env *)tmp->content)->value, ':'));
}
