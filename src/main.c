/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/04 13:01:50 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int __attribute__((unused))ac, __attribute__((unused))char *av[], char *env[])
{
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
			builtin_pwd(env);
		
		// test = ft_split(str, ' ');
		// int i;
		// i = -1;
		// while (test[++i])
		// 	printf("%s\n", test[i]);
		// if (search_path(&hpaths, &cmd, str))
		// 	exec_cmd(&cmd, av, env);
	} */
	return (0);
}
