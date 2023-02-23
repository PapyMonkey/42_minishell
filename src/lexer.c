/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:49:47 by bgales            #+#    #+#             */
/*   Updated: 2023/02/23 16:45:45 by bgales           ###   ########.fr       */
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
	if(str[i] != '\0')
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

	i = 0;
	wc = 1;

	while(str[i])
	{
		while ((str[i] == '\'' || str[i] == '\"'))
		{
			if (i > 0 && str[i - 1] == 32)
				wc++;
			if (i > 0 && str[i - 1] != 32)
				break;
			i += itter_quote(str, str[i]);
			if (str[i] != 32 && i > 0)
			{
				while (str[i] != 32 && str[i] != '\'' && str[i] != '\"' && str[i])
					i++;
			}
		}
		if (str[i] == 32)
		{
			while (str[i] == 32 && str[i])
				i++;
				wc++;
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
		if (str[i])
			i++;
	}
	return (wc);
}

char **to_split(char *str)
{
	char	*start;
	char	**ret;
	int		len;
	int		i;
	int		tab;

	len = 0;
	i = 0;
	tab = 0;
	ret = malloc(sizeof(char *) * (word_count(str) + 1));
	if (!ret)
	{
		printf("Malloc failure\n");
		exit (0);
	}

	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if(i > 0 && str[i - 1] != 32)
				break;
			start = &str[i];
			i +=itter_quote(&str[i], str[i]);
			len += itter_quote(&str[i], str[i]);
			if (str[i] != 32)
			{
				while (str[i] && str[i] != 32)
				{
					len++;
					i++;
				}
				ret[tab++] = ft_substr(start, 0, len);
				len = 0;
			}
		}
		if (str[i] && str[i] != 32)
		{
			start = &str[i];
			while (str[i] && str[i] != 32)
			{
				i++;
				len++;
			}
			ret[tab++] = ft_substr(start, 0, len);
			len = 0;
		}
		if (str[i])
			i++;
	}
	return (ret);
}

char	*del_quotes(char *split)
{
	char *ret;
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	while (split[i])
	{
		if (split[i] != '\'' && split[i] != '\"')
			char_count++;
		i++;
	}
	ret = malloc(sizeof(char) * (char_count + 1));
	char_count = 0;
	i = 0;
	while(split[i])
	{
		if (split[i] != '\'' && split[i] != '\"')
			ret[char_count++] = split[i];
		i++;
	}
	ret[char_count] = '\0';
	return (ret);
}

t_lexer *ft_split_args(char *str)
{
	int	i;
	t_lexer *ret;
	char	**split;

	i = -1;

	if (!str)
		return (NULL);
	if (!!closed_quotes(str))
		return (NULL);
	str = ft_strtrim(str, " ");
	split = to_split(str);
	while(split[++i])
		split[i] = del_quotes(split[i]); //leaks ici 
	i = -1;
	while (split[++i])
		printf("%s\n", split[i]);

	return (ret);
}

int main (int argc, char **argv)
{
	ft_split_args(argv[1]);
}