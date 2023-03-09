/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:33:15 by bgales            #+#    #+#             */
/*   Updated: 2023/03/09 17:45:05 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*del_whitespace(t_list **list)
{
	t_list	*ptr;
	t_list	*tmp;
	t_arg	*arg;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg->type == WHITE_SPACE)
			ft_lstremove(list, ptr, free_lstcontent);
		ptr = ptr->next;
	}
	return (0);
}
