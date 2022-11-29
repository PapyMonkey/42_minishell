/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:10:27 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/29 15:49:25 by mgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int	exec_cmd(t_cmd *cmd, char *av[], char *env[])
{
	int	pid;
	int	status;

	pid = fork();
	if (!pid)
	{
		execve(cmd->cmdpath, av, env);
		return (1);
	}
	else
		wait(&status);
	return (1);
}

static char	*ft_strjoin(char *str, char *add)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(*str) * (strlen(str) + strlen(add) + 2));
	if (!ret)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i])
		ret[++j] = str[i];
	ret[j + 1] = '/';
	i = -1;
	j += 1;
	while (add[++i])
		ret[++j] = add[i];
	ret[j + 1] = '\0';
	return (ret);
}

int	search_path(t_paths *hpaths, t_cmd *cmd, char *str)
{
	t_paths	*ppaths;

	ppaths = hpaths;
	while (ppaths)
	{
		cmd->cmdpath = ft_strjoin(ppaths->str, str);
		if (!access(cmd->cmdpath, X_OK))
			return (1);
		ppaths = ppaths->next;
	}
	return (0);
}

static char	*trimpath(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	while (str[++i])
		;
	ret = malloc(sizeof(*str) * (i - 4));
	i = 4;
	j = -1;
	while (str[++i])
		ret[++j] = str[i];
	ret[j + 1] = '\0';
	return (ret);
}

int	get_path(char *env[], t_paths *hpaths)
{
	char	**penv;
	t_paths	*ppaths;
	int		i;

	i = -1;
	while (env[++i])
		if (!strncmp(env[i], "PATH=", 5))
			penv = ft_split(env[i], ':');
	if (!penv)
		return (0);
	ppaths = hpaths;
	ppaths->str = trimpath(penv[0]);
	i = 0;
	while (penv[++i])
	{
		ppaths->next = malloc(sizeof(*ppaths));
		if (!ppaths->next)
			return (0);
		ppaths = ppaths->next;
		ppaths->str = penv[i];
	}
	ppaths->next = NULL;
	return (1);
}
