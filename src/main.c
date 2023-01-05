/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/05 11:19:33 by aguiri           ###   ########.fr       */
=======
/*   Updated: 2022/11/30 16:19:18 by aguiri           ###   ########.fr       */
>>>>>>> 2eca6d0 (feat(builtin): add several builtins functions and minor changes)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(__attribute__((unused))int argc,
		__attribute__((unused))char **argv,
		char **envp)
{
<<<<<<< HEAD
	t_var	*var;
	t_list	*tmp;
	char	*str;

	var = init(env);
	// while (var->l_pth->next)
	// {
	// 	tmp = var->l_pth;
	// 	printf("%s\n", (char *)var->l_pth->content);
	// 	var->l_pth = tmp->next;
	// }
	/* while (1)
	{
		str = readline("$> ");
		add_history((const char *)str);

		if (!strcmp("pwd", str))
			b_pwd(env);
		
		// test = ft_split(str, ' ');
		// int i;
		// i = -1;
		// while (test[++i])
		// 	printf("%s\n", test[i]);
		// if (search_path(&hpaths, &cmd, str))
		// 	exec_cmd(&cmd, av, env);
	} */
=======
	t_paths		hpaths;
	char		*str;
	char		**test;

	if (!get_path(envp, &hpaths))
		return (0);
	while (1)
	{
		str = readline("$> ");
		add_history((const char *)str);
		if (b_routine(str, envp))
			continue ;
	}
>>>>>>> 2eca6d0 (feat(builtin): add several builtins functions and minor changes)
	return (0);
}
