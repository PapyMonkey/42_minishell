/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exp_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:30:14 by aguiri            #+#    #+#             */
/*   Updated: 2023/02/25 16:51:48 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*search_exp_elem(t_list *const l_exp, const char *key)
{
	t_list	*tmp_exp;
	t_list	*tmp_next;
	int		key_len;

	tmp_exp = l_exp;
	key_len = ft_strlen(key);
	while (tmp_exp)
	{
		if (!ft_strncmp(
				(char *)tmp_exp->content,
				key,
				key_len)
			&& ft_strlen((char *)tmp_exp->content) == key_len)
			return (tmp_exp);
		tmp_next = tmp_exp->next;
		tmp_exp = tmp_next;
	}
	return (NULL);
}
