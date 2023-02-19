/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:53:41 by aguiri            #+#    #+#             */
/*   Updated: 2023/02/19 16:56:16 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*init(char **envp)
{
	t_var	*var_out;

	var_out = malloc(sizeof(t_var));
	if (!var_out)
		err_malloc_exit();
	var_out->l_env = NULL;
	init_env(var_out, envp);
	return (var_out);
}
