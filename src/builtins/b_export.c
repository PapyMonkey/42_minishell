/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:35:35 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 02:35:22 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Display environment and exported variables with no arguments.

@param var     Variable structure.
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

/*
@brief Create an exported variable.

@param var     Variable structure.
@param key     Key of the variable to export.
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

/*
@brief Create an environment variable from an exported variable.

@param var     Variable structure.
@param key     Key of the variable to create.
@param index   Index of the variable in the command_array.
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
