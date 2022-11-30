/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:43 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/30 10:44:40 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	issep(char c, char *sep)
{
	int	i;

	i = -1;
	while (sep[++i])
		if (sep[i] == c)
			return (1);
	return (0);
}

static int is_syntax_ok(const char *str, const int n)
{
	int	n_end;
	int	i;
	int is_quote_open;
	int	is_double_open;

	n_end = n;
	i = n - 1;
	is_quote_open = 0;
	is_double_open = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			if (is_quote_open)
				is_quote_open = 1;
			else if (!is_quote_open)
				is_quote_open = 0;
		}
	}
	return (n_end);
}
