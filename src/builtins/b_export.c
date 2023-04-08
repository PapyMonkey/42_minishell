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

/**
@brief Create and add an environnement variable to the ENV list.

@param var Variable that contains all the other useful ones.
@param str Argument/input string.
*/
static void	exp_create_env(t_var *var, char **key_and_value)
{
	char	*key;
	t_list	*ptr_exp;
	t_list	*ptr_env;

	key = key_and_value[0];
	ptr_exp = search_exp_elem(var->l_exp, key);
	ptr_env = search_env_elem(var->l_env, key);
	if (ptr_exp)
		ft_lstremove(&var->l_exp, ptr_exp, &free);
	if (ptr_env)
		ft_lstremove(&var->l_env, ptr_env, &free);
	ft_lstadd_back(
		&var->l_env,
		ft_lstnew(init_env_element(var->command_array[1]))
		);
}

void	b_export(t_var *var)
{
	int		is_env;
	char	**key_and_value;

	is_env = 0;
	if (var->command_array[1] && ft_strchr(var->command_array[1], '='))
		is_env = 1;
	key_and_value = export_split(var->command_array[1], '=');
	if (!key_and_value)
		exp_no_args(var);
	else if (!is_env)
		exp_create(var, key_and_value[0]);
	else if (is_env)
		exp_create_env(var, key_and_value);
	free(key_and_value);
}
