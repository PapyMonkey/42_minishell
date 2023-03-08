/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:28:36 by bgales            #+#    #+#             */
/*   Updated: 2023/03/08 19:46:14 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*minishell_join(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*out;

	if (!s1)
		return (ft_strdup(s2));
	out = malloc(sizeof(char) * ((len_s1 = ft_strlen(s1))
				+ (len_s2 = ft_strlen(s2)) + 1));
	if (out == NULL)
		return (NULL);
	i = -1;
	while (++i < len_s1)
	{
		out[i] = (char) s1[i];
	}
	i = -1;
	while (++i < len_s2)
	{
		out[i + len_s1] = (char) s2[i];
	}
	out[len_s1 + len_s2] = '\0';
	free (s1);
	return (out);
}

int	pipe_redir_finder(char *str)
{
	if (*str == '|')
		return (PIPE);
	if (*str == '<' && *(str + 1) != '<')
		return (REDIR_IN);
	if (*str == '>' && *(str + 1) != '>')
		return (REDIR_OUT);
	if (*str == '<' && *(str + 1) == '<')
		return (HERE_DOC);
	if (*str == '>' && *(str + 1) == '>')
		return (APPEND);
	return (0);
}

int	itter_quote(char *str, char c, int *len)
{
	int	i;

	i = 1;
	*len += 1;
	while (str[i] && str[i] != c)
	{
		i++;
		*len += 1;
	}
	if (str[i] != '\0')
	{
		i++;
		*len += 1;
	}
	return (i);
}

int	itter_enum(char *str)
{
	if (pipe_redir_finder(str) == PIPE || pipe_redir_finder(str) == REDIR_IN
		|| pipe_redir_finder(str) == REDIR_OUT)
		return (1);
	else if (!pipe_redir_finder(str))
		return (0);
	else
		return (2);
}

int	closed_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (!str[i])
				return (1);
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (!str[i])
				return (1);
		}
	}
	return (0);
}
