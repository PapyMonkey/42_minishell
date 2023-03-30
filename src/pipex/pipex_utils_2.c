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
	// t_list	*tmp;
	// char	**str_previous;
	// char	**str_current;
	//
	// tmp = l_arg;
	// if (tmp && ((t_arg *)(tmp->content))->type == EXEC)
	// {
	// 	str_previous = ft_strjoin(((t_arg *)tmp->content)->content, "");
	// 	tmp = tmp->next;
	// }
	// while (tmp && is_next_cmd(tmp->content))
	// {
	// 	// str_current = ft_strdup((((t_arg *)(tmp->content))->content));
	// 	tmp = tmp->next;
	// }
	int		n_args;
	char	**cmd;
	t_list	*tmp;
	int		i;

	n_args = ft_pipex_count_args(l_arg);
	cmd = malloc(sizeof(char *) * (n_args + 1));
	if (!cmd)
		err_malloc_exit();
	cmd[n_args] = 0;
	tmp = l_arg;
	i = -1;
	while (++i < n_args)
		cmd[i] = get_arg_content(tmp);
		// cmd[i] = ((t_arg *)tmp->content)->content;
	return (cmd);
}
