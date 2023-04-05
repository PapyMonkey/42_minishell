/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:49:59 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/26 15:00:45 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

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

void	exec_redirect_fd(int old_fd, int new_fd)
{
	if (old_fd != new_fd && old_fd != 0)
	{
		if (dup2(old_fd, new_fd) == -1)
			err_put_exit();
		else
			close(old_fd);
	}
}

char	**build_env_array(struct s_list *l_env)
{
	t_list	*tmp;
	int		env_size;
	int		i;
	char	**env_array;
	char	*key_with_equal_sign;

	tmp = l_env;
	env_size = ft_lstsize(tmp);
	env_array = malloc(sizeof(char *) * (env_size + 1));
	if (!env_array)
		err_malloc_exit();
	env_array[env_size] = 0;
	tmp = l_env;
	i = -1;
	while (++i < env_size)
	{
		key_with_equal_sign = ft_strjoin(((t_env *)tmp->content)->key, "=");
		env_array[i] = ft_strjoin(
			key_with_equal_sign, ((t_env *)tmp->content)->value);
		free(key_with_equal_sign);
		tmp = tmp->next;
	}
	return(env_array);
}
