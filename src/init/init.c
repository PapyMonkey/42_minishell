/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:53:41 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 17:21:50 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*init(char **envp)
{
	t_var	*var_out;

	var_out = malloc(sizeof(t_var));
	if (!var_out)
		err_malloc_exit();
	init_env(var_out, envp);
	return (var_out);
}
