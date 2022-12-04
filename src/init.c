/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:53:41 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 12:56:49 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_paths(
	struct s_var *var,
	char *envp)
{
	char	**path_splitted;
	int		i;

	path_splitted = ft_split(ft_strtrim(envp, "PATH="), ':');
	i = -1;
	while (path_splitted[++i])
		ft_lstadd_back(&var->l_pth, ft_lstnew(path_splitted[i]));
	free(path_splitted);
}

static void	init_env(
	struct s_var *var,
	char **envp)
{
	int	i;

	var->l_env = malloc(sizeof(t_list));
	if (!var->l_env)
		err_malloc_exit();
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			init_paths(var, envp[i++]);
		// TODO: Initiate the list of env.	
		// else
		// {
		// }
	}
}

t_var	*init(char **envp)
{
	t_var	*var_out;

	var_out = malloc(sizeof(t_var));
	if (!var_out)
		err_malloc_exit();
	var_out->l_pth = NULL;
	init_env(var_out, envp);
	return (var_out);
}
