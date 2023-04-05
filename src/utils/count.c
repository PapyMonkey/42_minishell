/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:06:08 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:08:05 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_argument(struct s_list *l_arg)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = l_arg;
	while (tmp && !is_separator(tmp))
	{
		count++;
		tmp = tmp->next;
	}
	return(count);
}

int count_command(struct s_list *l_arg)
{
	int			count;
	t_list		*tmp;
	t_enum_type	arg_type;

	count = 0;
	tmp = l_arg;
	while (tmp)
	{
		arg_type = get_arg_type(tmp);
		if (is_command(tmp))
			count++;
		tmp = tmp->next;
	}
	return(count);
}

int count_separator(struct s_list *l_arg)
{
	int		count;
	t_list	*tmp;
	t_enum_type	arg_type;

	count = 0;
	tmp = l_arg;
	while (tmp)
	{
		arg_type = get_arg_type(tmp);
		if (is_separator(tmp))
			count++;
		tmp = tmp->next;
	}
	return(count);
}
