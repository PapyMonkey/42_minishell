/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:40:04 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:28:24 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void setup_fd(
	t_var *var,
	int	index,
	int fd_old,
	int fd_new)
	t_list	*previous_separator;

	previous_separator = get_previous_sep(var, index);
	if (!previous_separator)
	{
		
	}
	else if (get_arg_type(previous_separator) == PIPE)
	{

	}
