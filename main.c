/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/29 15:56:22 by mgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include "minishell.h"

int	main(int __attribute__((unused))ac, char *av[], char *env[])
{
	t_paths		hpaths;
	t_cmd		cmd;
	char		*str;

	if (!get_path(env, &hpaths))
		return (0);
	while (1)
	{
		str = readline("$> ");
		add_history((const char *)str);
		if (search_path(&hpaths, &cmd, str))
			exec_cmd(&cmd, av, env);
		else
			perror("idk");
	}
	return (0);
}
