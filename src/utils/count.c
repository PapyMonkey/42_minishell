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

int		count_separator(struct s_list *l_arg)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = l_arg;
	while (tmp)
	{
		if (get_arg_type(tmp) == EXEC)
			count++;
		tmp = tmp->next;
	}
	return(count);
}
