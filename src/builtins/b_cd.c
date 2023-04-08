/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:25:16 by bgales            #+#    #+#             */
/*   Updated: 2023/04/07 17:59:25 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: Documentation

/* static void	cd_add_env_element(
	t_list *l_env,
	char *key,
	char *value)
{
	t_env	*element;

	element = malloc(sizeof(t_env));
	if (!element)
		err_malloc_exit();
	element->key = ft_strdup(key);
	if (!element->key)
		err_malloc_exit();
	element->value = ft_strdup(value);
	if (!element->value)
		err_malloc_exit();
	ft_lstadd_back(&l_env, ft_lstnew(element));
} */

// NOTE: Documentation
static void	cd_update_env(
	t_var *var,
	char *key,
	char *value)
{
	t_list	*ptr_elem;

	ptr_elem = search_env_elem(var->l_env, key);
	if (!ptr_elem)
		return ;
	free(((t_env *)ptr_elem->content)->value);
	((t_env *)ptr_elem->content)->value = ft_strdup(value);
}

void	b_cd(t_var *var)
{
	char	pwd[BUFFER_SIZE];

	if (get_number_arguments(var->current_arg->next) > 1)
		err_custom_exit("bash: cd: too many arguments\n");
	if (get_arg_type(var->current_arg->next) != ARG)
		err_custom_exit("bash: cd: invalid option\n");
	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "OLDPWD", pwd);
	if (chdir(var->command_array[1]) != 0)
		err_put_exit();
	getcwd(pwd, BUFFER_SIZE);
	cd_update_env(var, "PWD", pwd);
	free(g_process.pwd);
	g_process.pwd = ft_strdup(pwd);
	if (!g_process.pwd)
		err_malloc_exit();
}
