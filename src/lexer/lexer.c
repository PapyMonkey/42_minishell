/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:49:47 by bgales            #+#    #+#             */
/*   Updated: 2023/04/06 17:38:39 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_split_args(char *str, t_list *env)
{
	t_list	*ret;

	if (!str)
		return (NULL);
	if (!!closed_quotes(str))
	{
		printf("missing closing quote");
		return (NULL);
	}
	if (str[0] == '\0')
		return (NULL);
	str = ft_strtrim(str, " ");
	ret = struct_init(str, env);
	if (ret != NULL)
		ret = struct_init_2(&ret);
	free(str);
	return (ret);
}
