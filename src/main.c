/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/03/27 18:39:47 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


	int	main(int argc, char **argv, char **env)
	{
		t_var	*var;
		t_list	*list;
		t_arg	*arg;
		char	*str;

		var = init(env);
		// get_signo();
		// while (var->l_pth->next)
		// {
		// 	tmp = var->l_pth;
		// 	printf("%s\n", (char *)var->l_pth->content);
		// 	var->l_pth = tmp->next;
		// }
		while (1)
		{
			str = readline("$> ");
			if (!str)
				exit (0);
			list =  ft_split_args(str, var->l_env);
			if (str[0])
			{
				add_history((const char *)str);
				b_routine(str, var); // si hors de ce "if", print l'env lorsqu'on presse entree
			}
			free(str);
			ft_lstiter(list, free_lstcontent);
			free (list);
			// if (search_path(&hpaths, &cmd, str))
			// 	exec_cmd(&cmd, av, env);
		}
		return (0);
	}
