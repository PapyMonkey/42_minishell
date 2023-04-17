/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:53:34 by aguiri            #+#    #+#             */
/*   Updated: 2023/02/25 17:47:36 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_identifier(char *const str)
{
	int		i;
	int		is_alpha;

	i = -1;
	is_alpha = 0;
	while (str[++i])
	{
		if (!is_alpha && ft_isalpha(str[i]))
			is_alpha = 1;
		if (!ft_isalnum(str[i]))
			return (EXIT_FAILURE);
	}
	if (!is_alpha)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_list	*check_arg_flag(t_list *const l_arg)
{
	t_list	*tmp;

	tmp = l_arg;
	while (tmp)
	{
		if (get_arg_type(tmp) == FLAG)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	check_exp_input(const char *str)
{
	if (ft_strchr(str, 39))
	{
		printf("export: \"%s\" not a valid identifier\n", str);
		return (EXIT_FAILURE);
	}
	if (*str == '=')
	{
		printf("export: \"%s\" not a valid identifier\n", str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
