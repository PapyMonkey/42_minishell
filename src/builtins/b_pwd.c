/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:45:15 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/06 04:12:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	b_pwd(t_list *const l_env)
{
	t_list	*tmp;

	tmp = search_env_elem(l_env, "PWD");
	if (tmp->next == NULL)
	{
		ft_printf("No PWD variable defined.\n");
		return ;
	}
	printf("%s\n", get_env_value(tmp));
} */

// NOTE: Documentation
static int	pwd_is_there_flag(t_list *const l_arg)
{
	t_list	*tmp;

	tmp = l_arg;
	while (tmp && !is_separator(tmp))
	{
		if (get_arg_type(tmp) == FLAG)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	b_pwd(t_var *const var)
{
	if (pwd_is_there_flag(var->current_arg))
		err_custom_exit("bash: pwd: invalid option\n");
	printf("%s\n", g_process.pwd);
}
