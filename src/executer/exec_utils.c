/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:49:59 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 01:06:41 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**exec_build_cmd(
	t_list *l_arg)
{
	int		n_args;
	char	**cmd;
	t_list	*tmp;
	int		i;

	n_args = count_argument(l_arg);
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

char	**exec_build_env(
	struct s_list *l_env)
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
	return (env_array);
}

void	exec_redirect_fd(
	int old_fd,
	int new_fd)
{
	if (old_fd != new_fd && old_fd != 0)
	{
		if (dup2(old_fd, new_fd) == -1)
			err_put_exit();
		else
			close(old_fd);
	}
}

char	*exec_try_access(
	char *command,
	char **path)
{
	int		i;
	char	*path_tmp;
	char	*path_join;

	if (!command)
		return (NULL);
	i = 0;
	while (path[i] != NULL)
	{
		path_tmp = ft_strdup(path[i]);
		ft_strlcat(path_tmp, "/", ft_strlen(path_tmp) + 2);
		path_join = ft_strjoin(path_tmp, command);
		if (access(path_join, X_OK) == 0)
			return (path_join);
		free(path_tmp);
		free(path_join);
		i++;
	}
	return (NULL);
}
