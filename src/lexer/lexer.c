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

// TODO: Documentation
static int	word_count(char *str)
{
	int		i;
	int		wc;
	int		no_segf;

	i = 0;
	no_segf = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] != 32)
		{
			if ((str[i] != '\'' && str[i] != '\"'))
				i++;
			while (str[i] && (str[i] == '\'' || str[i] == '\"'))
				i += itter_quote(&str[i], str[i], &no_segf);
		}
		while (str[i] && str[i] == 32)
			i++;
		wc++;
	}
	return (wc);
}

t_list	*ft_split_args(char *str, t_list *env)
{
	int		i;
	t_list	*ret;
	char	**split;

	i = -1;
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
	i = -1;
	return (ret);
}
