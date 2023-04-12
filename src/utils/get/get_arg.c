/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:49:30 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/05 22:59:53 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_arg_content(const t_list *l_arg_element)
{
	if (!l_arg_element)
		return (NULL);
	return (((t_arg *)l_arg_element->content)->content);
}

t_enum_type	get_arg_type(const t_list *l_arg_element)
{
	if (!l_arg_element)
		return (0);
	return (((t_arg *)l_arg_element->content)->type);
}

int	get_number_arguments(t_list *const l_arg)
{
	t_list	*tmp;
	int		count_arguments;

	tmp = l_arg;
	count_arguments = 0;
	while (tmp && !is_separator(tmp))
	{
		count_arguments++;
		tmp = tmp->next;
	}
	return (count_arguments);
}
