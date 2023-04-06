/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/06 03:10:50 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute(t_var *var)
{
	int		fd[2];

	var->sep_last = var->l_arg;
	var->current_arg = var->l_arg;
	var->n_seps = count_separator(var->l_arg); //TODO: A enlever ?
	var->n_cmds = count_command(var->l_arg);
	var->n_redirs = count_redirections(var->l_arg);
	printf("Number of commands : %d\n", var->n_cmds);
	printf("Number of separators : %d\n", var->n_seps);
	printf("---------------------------------------------------------------\n");
	if (pipe(fd) == -1)
		err_put_exit();
	close(fd[WRITE_END]);
	executer(var, 0, fd[READ_END]);
	close(fd[READ_END]);
}

int	main(int argc, char **argv, char **env)
{
	t_var	*var;
	char	*input;

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
		input = readline("$> ");
		if (!input) // ctrl + d
			exit (0);
		var->l_arg = ft_split_args(input, var->l_env);
		if (var->l_arg == NULL)
			printf("Missing closing quote\n");
		if (input[0])
		{
			add_history((const char *)input);
			// TODO: Move this in exec_command function
			// Change the way the routine function is called to handle the 
			// chained list.
			b_routine(input, var); // si hors de ce "if", print l'env lorsqu'on presse entree
		}
		// ft_lstiter(var->l_arg, print_arg_elem);
		execute(var);
		free(input);
		ft_lstiter(var->l_arg, free_lstcontent);
		free(var->l_arg);
		// system("leaks minishell"); // Checks leaks
	}
	return (0);
}
