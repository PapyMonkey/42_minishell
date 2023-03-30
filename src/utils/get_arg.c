/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:49:30 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 05:28:25 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_arg_content(t_list *l_arg_element)
{
	return (((t_arg *)l_arg_element)->content);
}

t_enum_type	get_arg_type(t_list *l_arg_element)
{
	return (((t_arg *)l_arg_element)->type);
}
