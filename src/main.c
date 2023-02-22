/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/02/22 11:22:43 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// int	main(int argc, char **argv, char **env)
// {
// 	t_var	*var;
// 	t_list	*tmp;
// 	char	*str;
// 	char	**test;
// 	int		i = -1;

// 	var = init(env);
// 	get_signo();
// 	// while (var->l_pth->next)
// 	// {
// 	// 	tmp = var->l_pth;
// 	// 	printf("%s\n", (char *)var->l_pth->content);
// 	// 	var->l_pth = tmp->next;
// 	// }
// 	while (1)
// 	{
// 		str = readline("$> ");
// 		if (!str) // ctrl + d
// 			exit (0);
// 		test = ft_split(str, ' ');
// 		if (test == NULL)
// 			printf("Missing closing quote\n");
// 		if (test)
// 		while(test[++i])
// 			printf("%s\n", test[i]);
// 		if (str[0] && test != NULL)
// 		{
// 			add_history((const char *)str);
// 			b_routine(str, var); // si hors de ce "if", print l'env lorsqu'on presse entree
// 		}
// 		free(str);
// 		i = -1;
// 		// if (search_path(&hpaths, &cmd, str))
// 		// 	exec_cmd(&cmd, av, env);
// 	}
// 	return (0);
// }
