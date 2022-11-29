/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:43 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/29 14:54:13 by mgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

static char	**ft_split_alloc(const char *str, char sep)
{
	char	**strs;
	int		i;
	int		new_str;
	int		len;

	i = -1;
	new_str = 2;
	len = 0;
	while (str[++i])
	{
		if (str[i] == sep && str[i + 1] != sep)
			new_str++;
		if (str[i] != sep)
			len++;
	}
	strs = malloc(sizeof(*strs) * new_str + sizeof(**strs) * (new_str + len));
	if (!strs)
		return (NULL);
	strs[0] = (char *)&(strs[new_str]);
	return (strs);
}

char	**ft_split(const char *str, char sep)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	strs = ft_split_alloc(str, sep);
	if (!strs)
		return (NULL);
	i = -1;
	j = -1;
	k = 0;
	while (str[++i])
	{
		if (str[i] != sep)
			strs[0][++j] = str[i];
		else
		{
			strs[0][++j] = '\0';
			strs[++k] = (char *)&(strs[0][j + 1]);
		}
	}
	strs[0][j + 1] = '\0';
	strs[k + 1] = NULL;
	return (strs);
}
