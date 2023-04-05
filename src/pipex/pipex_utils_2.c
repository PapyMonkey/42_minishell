/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:18:46 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 06:58:29 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **exec_build_cmd(t_list *l_arg)
{
	int		n_args;
	char	**cmd;
	t_list	*tmp;
	int		i;

	n_args = count_argument(l_arg);
	printf("n_args : %d\n", n_args);
	cmd = malloc(sizeof(char *) * (n_args + 1));
	if (!cmd)
		err_malloc_exit();
	cmd[n_args] = 0;
	tmp = l_arg;
	i = 0;
	while (i < n_args)
	{
		cmd[i] = get_arg_content(tmp);
		tmp = tmp->next;
		i++;
	}
	return (cmd);
}
