/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:35:35 by aguiri            #+#    #+#             */
/*   Updated: 2023/02/27 13:19:34 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: Documentation
/**
@brief Print the export list to the standard output.

@param var Variable that contains all the other useful ones.
*/
static void	exp_no_args(const t_var *var)
{
	t_list	*tmp_env;
	t_list	*tmp_exp;

	tmp_env = var->l_env;
	if (tmp_env)
		ft_lstiter(tmp_env, print_env_exp_format);
	tmp_exp = var->l_exp;
	if (tmp_exp)
		ft_lstiter(tmp_exp, print_exp_elem);
}

// NOTE: Documentation
/**
@brief Create and add an export value to the EXP list, only if it does not
		already exist in the ENV and EXP lists.

@param var Variable that contains all the other useful ones.
@param str Argument/input string.
*/
static void	exp_create(t_var *var, char *key)
{
	t_list	*ptr_exp;
	t_list	*ptr_env;

	ptr_exp = search_exp_elem(var->l_exp, key);
	ptr_env = search_env_elem(var->l_env, key);
	if (ptr_exp || ptr_env)
		return ;
	ft_lstadd_back(
		&var->l_exp,
		ft_lstnew(ft_strdup(key))
		);
}

// NOTE: Documentation
/**
@brief Create and add an environnement variable to the ENV list.

@param var Variable that contains all the other useful ones.
@param str Argument/input string.
*/
static void	exp_create_env(t_var *var, char *key, int index)
{
	t_list	*ptr_exp;
	t_list	*ptr_env;

	ptr_exp = search_exp_elem(var->l_exp, key);
	ptr_env = search_env_elem(var->l_env, key);
	if (ptr_exp)
		ft_lstremove(&var->l_exp, ptr_exp, &free);
	if (ptr_env)
		ft_lstremove(&var->l_env, ptr_env, &free);
	ft_lstadd_back(
		&var->l_env,
		ft_lstnew(init_env_element(var->command_array[index]))
		);
}

int	b_export(t_var *var)
{
	t_list	*flag;
	int		index;
	char	**key_and_value;

	if (!var->command_array[1])
	{
		exp_no_args(var);
		return (EXIT_SUCCESS);
	}
	flag = check_arg_flag(var->cmd_current);
	if (flag)
		return (err_d("export", get_arg_content(flag), "invalid option", 2));
	index = 0;
	while (var->command_array[++index])
	{
		key_and_value = export_split(var->command_array[index], '=');
		if (var->command_array[index]
			&& ft_strchr(var->command_array[index], '='))
			exp_create_env(var, key_and_value[0], index);
		else
			exp_create(var, key_and_value[0]);
		free_2d_char(key_and_value);
	}
	g_process.return_code = 0;
	return (EXIT_SUCCESS);
}
