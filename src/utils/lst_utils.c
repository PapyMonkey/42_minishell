/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:34:58 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/03 17:46:57 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lstcontent(void *content)
{
	t_arg	*arg;

	arg = (t_arg *)content;
	free(arg->content);
	free(arg);
}

t_arg	*t_arg_cpy(void *arg)
{
	t_arg	*ret;
	t_arg	*ptr;

	ptr = arg;
	ret = malloc(sizeof(t_arg));
	ret->content = ft_strdup(ptr->content);
	ret->type = ptr->type;
	return (ret);
}
