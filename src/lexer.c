/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:49:47 by bgales            #+#    #+#             */
/*   Updated: 2023/02/22 14:37:31 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum{
	WORD,
	PIPE,
	HERE_DOC,
	REDIR_IN,
	APPEND,
	REDIR_OUT
};

struct s_lexer
{
	char *value;
	int type;
	struct s_lexer *next;
}; typedef struct s_lexer t_lexer;


int closed_quotes(char *str)
{
	int i;

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

int	itter_quote(char *str, char c)
{
	int i;

	i = 1;
	i++;
	while (str[i] && str[i] != c)
		i++;
	i++;
	return (i);
}

int	enum_finder(char *str)
{
	if (*str == '|')
		return (PIPE);
	if (*str == '<' && *(str + 1) != '<')
		return (REDIR_IN);
	if (*str == '<' && *(str + 1) == '<')
		return (HERE_DOC);
	if (*str == '>' && *(str + 1) != '>')
		return(REDIR_OUT);
	if (*str == '>' && *(str + 1) == '>')
		return(APPEND);
	return (0);
}

int	word_count(char *str)
{
	int		i;
	int		wc;

	i = -1;
	wc = 1;

	while(str[++i])
	{
		while ((str[i] == '\'' || str[i] == '\"'))
		{
			if (i > 0)
				wc++;
			if (i > 0 && str[i - 1] != 32)
				break;
			i += itter_quote(str, str[i]);
			if (str[i] != 32 && i > 0)
			{
				while (str[i] != 32 && *str != '\'' && str[i] != '\"' && *str)
					i++;
			}
		}
		if (str[i] == 32)
		{
			while (str[i] == 32)
				i++;
			if (str[i] != '\'' && str[i] != '\"')
				wc++;
			else
				i--;

		}
		if (enum_finder(str))
		{
			if (!(enum_finder(str) % 2))
			{
				wc++;
				i++;
			}
			else
				wc++;
		}
	}
	printf("word counted =%d\n", wc);

	return (wc);
}
char **to_split(char *str)
{
	char	*start;
	char	**ret;
	int		len;
	int		i;

	len = 0;
	i = 0;
	ret = malloc(sizeof(char *) * word_count(str));
	while(*str)
	{
		start = str;
		if ((*str == '\'' || *str == '\"') && *(str - 1) == 32)
		{
			start = str;
			len += itter_quote(str, *str);
			str += len;
			ret[i++] = ft_substr(start, 0, len);
			len = 0;
		}
		if (*str == 32)
		{
			ret[i++] = ft_substr(start, 0 ,len);
			while (*str == 32)
				str++;
			start = str;
			len = 0;
		}
		if (enum_finder(str))
		{
			if (!(enum_finder(str) % 2))
			{
				ret[i++] = ft_substr(start, 0, 2);
				str++;
			}
			else
				ret[i++] = ft_substr(start, 0, 1);
			len = 0;
		}
		str++;
		len++;

	}
	return (ret);
}

t_lexer *ft_split_args(char *str)
{
	int	i;
	t_lexer *ret;
	char	**split;

	i = -1;

	if (!!closed_quotes(str))
		return (NULL);
	if (!str)
		return (NULL);
	str = ft_strtrim(str, " ");
	split = to_split(str);

	return (ret);
}

int main (int argc, char **argv)
{
	ft_split_args(argv[1]);
}