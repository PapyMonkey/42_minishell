/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:50:02 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 01:58:03 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * \brief		Check if the given character is a separator or not.
 *
 * \param c		Character to be tested.
 * \param sep	Separator.
 * \return		1 if it is, 0 otherwise.
 */
static int	u_char_is_sep(char c, char sep)
{
	return (c == sep || c == '\0');
}

/**
 * \brief		Count the numbers of words in the string based on the
 * 				given separators.
 *
 * \param str	String containing the words.
 * \param c		Delimiting character.
 *
 * \return  	Number of words counted.
 */
static int	u_count_words(char *str, char c)
{
	int	i;
	int	words;

	i = -1;
	words = 1;
	while (str[++i] != '\0')
	{
		if (u_char_is_sep(str[i], c))
		{
			words++;
			break ;
		}
	}
	return (words);
}

/**
 * \brief		Write a word in a destination string.
 *
 * \param dest	Destination string.
 * \param src	String containing the words.
 * \param c		Delimiting character.
 */
static void	ft_write_words(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * \brief		Write the different words in a destination 2D array.
 *
 * \param str_split	Destination 2D array.
 * \param str		String containing the words.
 * \param c			Delimiting character.
 */
static void	ft_write_tab(char **str_split, const char *str, char c)
{
	int	i;
	int	j;
	int	n_word;
	int	sep_passed;

	i = 0;
	n_word = 0;
	sep_passed = 0;
	while (n_word < 2 && str[i] != '\0')
	{
		if (u_char_is_sep(str[i], c) && !sep_passed)
		{
			i++;
			sep_passed = 1;
			continue ;
		}
		j = 0;
		while (!u_char_is_sep(str[i + j], c))
			j++;
		str_split[n_word] = malloc(sizeof(char) * (j + 1));
		if (!str_split[n_word])
			err_exit(strerror(errno), NULL, errno);
		ft_write_words(str_split[n_word++], str + i, j);
		i += j;
	}
}

char	**export_split(char const *s, char c)
{
	char	**str_splitted;
	int		n_words;

	if (s == NULL)
		return (NULL);
	if (s[0] == '=')
		err_exit((char *)s, "not a valid identifier", 1);
	n_words = u_count_words((char *) s, c);
	str_splitted = malloc(sizeof(char *) * (n_words + 1));
	if (!str_splitted)
		err_exit(strerror(errno), NULL, errno);
	str_splitted[n_words] = 0;
	ft_write_tab(str_splitted, s, c);
	return (str_splitted);
}
