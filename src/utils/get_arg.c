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
	return (((t_arg *)l_arg_element->content)->content);
}

t_enum_type	get_arg_type(const t_list *l_arg_element)
{
	return (((t_arg *)l_arg_element->content)->type);
}
