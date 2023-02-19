/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/02/19 18:43:14 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int argc, char **argv, char **env)
{
	t_var	*var;
	t_list	*tmp;
	char	*str;
	char	**test;

	var = init(env);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	// while (var->l_pth->next)
	// {
	// 	tmp = var->l_pth;
	// 	printf("%s\n", (char *)var->l_pth->content);
	// 	var->l_pth = tmp->next;
	// }
	while (1)
	{
		str = readline("$> ");
		add_history((const char *)str);
		if (!str) // ctrl + d
			exit (0);
		if (str[0]) // sans cette condition print l'env si je fais entree.
			b_routine(str, var);
		test = ft_split(str, ' ');
		int i;
		i = -1;
		// while (test[++i])
		// 	printf("%s\n", test[i]);
		// if (search_path(&hpaths, &cmd, str))
		// 	exec_cmd(&cmd, av, env);
	}
	return (0);
}
