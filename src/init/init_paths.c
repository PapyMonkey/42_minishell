/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:30:37 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 13:30:57 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_paths(
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
