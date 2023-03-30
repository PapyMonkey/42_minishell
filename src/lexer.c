/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:49:47 by bgales            #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/03/28 15:52:03 by bgales           ###   ########.fr       */
=======
/*   Updated: 2023/03/25 21:50:47 by aguiri           ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	word_count(char *str)
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

char	**to_split(char *str)
{
	char	*start;
	char	**ret;
	int		len;
	int		i;
	int		tab;

	ret = malloc(sizeof(char *) * (word_count(str)
				+ (len = 0) + (i = 0) + (tab = 0) + 1));
	while (str[i])
	{
		start = &str[i];
		while (str[i] && str[i] != 32)
		{
			if ((str[i] != '\'' && str[i] != '\"') && i++ != -1)
				len++;
			while (str[i] && (str[i] == '\'' || str[i] == '\"'))
				i += itter_quote(&str[i], str[i], &len);
		}
		ret[tab++] = ft_substr(start, 0, len);
		len = 0;
		while (str[i] && str[i] == 32)
			i++;
	}
	ret[tab] = NULL;
	return (ret);
}

char	*del_quotes(char *split)
{
	char	*ret;
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
	while (split[i])
	{
		if (split[i] != '\'' && split[i] != '\"')
			ret[char_count++] = split[i];
		i++;
	}
	ret[char_count] = '\0';
	return (ret);
}

<<<<<<< Updated upstream
t_list	*ft_split_args(char *str, t_list *env)
=======
t_list	*ft_split_args(char *str)
>>>>>>> Stashed changes
{
	int		i;
	t_list	*ret;
	char	**split;

	i = -1;
	if (!str)
		return (NULL);
	if (!!closed_quotes(str))
<<<<<<< Updated upstream
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
=======
		return (NULL);
	if (str[0] == '\0')
		return (NULL);
	str = ft_strtrim(str, " ");
	ret = struct_init(str);
	ret = struct_init_2(&ret);
>>>>>>> Stashed changes
	free(str);
	i = -1;
	return (ret);
}
<<<<<<< Updated upstream
=======

// int	main(int argc, char **argv)
// {
// 	t_list	*list;
//
// 	list = ft_split_args(argv[1]);
// 	system("leaks minishell");
// 	ft_lstiter(list, *print_arg_elem);
//
// }
>>>>>>> Stashed changes
