/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:49:59 by aguiri            #+#    #+#             */
/*   Updated: 2022/05/31 20:24:38 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmds	ft_pipex_construct(int argc, char **argv, char **envp)
{
	t_cmds	out;

	out.args_nb = argc;
	out.args = argv;
	if (!envp)
	{
		ft_printf("Error : no environnement variable");
		exit (EXIT_FAILURE);
	}
	out.envp = envp;
	out.path = ft_split_path(out.envp);
	out.pwd = ft_get_pwd(out.envp);
	return (out);
}

void	ft_pipex_deconstruct(t_cmds cmds)
{
	int	i;

	i = 0;
	while (cmds.path[i])
		free(cmds.path[i++]);
	free(cmds.path);
	free(cmds.pwd);
}

void	ft_pipex_redirect(int old_fd, int new_fd)
{
	if (old_fd != new_fd)
	{
		if (dup2(old_fd, new_fd) == -1)
			ft_error_put_exit();
		else
			close(old_fd);
	}
}
