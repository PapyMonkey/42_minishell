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

// /**
// @brief Print the export list to the standard output.

// @param var Variable that contains all the other useful ones.
// */
// static void	exp_no_args(const t_var *var)
// {
// 	t_list	*tmp_env;
// 	t_list	*tmp_exp;

// 	tmp_env = var->l_env;
// 	ft_lstiter(tmp_env, print_env_exp_format);
// 	tmp_exp = var->l_exp;
// 	ft_lstiter(tmp_exp, print_exp_elem);
// }

// /**
// @brief Create and add an export value to the EXP list, only if it does not
// 		already exist in the ENV and EXP lists.

// @param var Variable that contains all the other useful ones.
// @param str Argument/input string.
// */
// static void	exp_create(t_var *var, char *key)
// {
// 	t_list	*ptr_exp;
// 	t_list	*ptr_env;

// 	ptr_exp = get_exp_elem(var->l_exp, key);
// 	ptr_env = get_env_elem(var->l_env, key);
// 	if (ptr_exp || ptr_env)
// 		return ;
// 	ft_lstadd_back(
// 		&var->l_exp,
// 		ft_lstnew(ft_strdup(key))
// 		);
// }

// /**
// @brief Create and add an environnement variable to the ENV list.

// @param var Variable that contains all the other useful ones.
// @param str Argument/input string.
// */
// static void	exp_create_env(t_var *var, char **key_and_value)
// {
// 	char	*key;
// 	char	*value;
// 	t_list	*ptr_exp;
// 	t_list	*ptr_env;

// 	key = key_and_value[0];
// 	value = key_and_value[1];
// 	ptr_exp = get_exp_elem(var->l_exp, key);
// 	ptr_env = get_env_elem(var->l_env, key);
// 	if (ptr_exp)
// 		ft_lstremove(&var->l_exp, ptr_exp, &free);
// 	if (ptr_env)
// 		ft_lstremove(&var->l_env, ptr_env, &free);
// 	ft_lstadd_back(
// 		&var->l_env,
// 		ft_lstnew(init_env_element(key_and_value))
// 		);
// }

// // TODO: Split seulement sur le premier '=' afin de garder la chaine si elle existe.
// void	b_export(t_var *var, const char *str)
// {
// 	int		i;
// 	int		is_env;
// 	char	**key_and_value;

// 	i = 7;
// 	while (ft_isspace(*(str + i)) && str + i)
// 		i++;
// 	if (check_exp_input(str + i))
// 		return ;
// 	is_env = 0;
// 	if (ft_strchr(str + i, '='))
// 		is_env = 1;
// 	key_and_value = u_split(str + i, '=');
// 	printf("<b_export.c> Key :%s\tValue : %s\n", key_and_value[0], key_and_value[1]);
// 	if (!key_and_value[0])
// 		exp_no_args(var);
// 	else if (!is_env)
// 		exp_create(var, key_and_value[0]);
// 	else if (is_env)
// 		exp_create_env(var, key_and_value);
// 	free(key_and_value);
// }
