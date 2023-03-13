/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:33:15 by bgales            #+#    #+#             */
/*   Updated: 2023/03/13 15:59:07 by bgales           ###   ########.fr       */
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
		{
			tmp = ptr;
			ptr = ptr->next;
			arg = ptr->content;
			ft_lstremove(list, tmp, free_lstcontent);
		}
		if (arg->type != WHITE_SPACE)
			ptr = ptr->next;
	}
	return (0);
}

int	no_quote(t_list **list)
{
	t_list	*ptr;
	t_arg	*arg;

	ptr = *list;
	while (ptr != NULL)
	{
		arg = ptr->content;
		if (arg->type == QUOTE || arg->type == D_QUOTE
			|| arg->type == OPEN_D_QUOTE || arg->type == CLOSE_D_QUOTE
			|| arg->type == OPEN_QUOTE || arg->type == CLOSE_QUOTE)
			break ;
		ptr = ptr->next;
	}
	if (ptr == NULL)
		return (1);
	else
		return (0);
}
