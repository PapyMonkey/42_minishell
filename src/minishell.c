/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/07 23:16:10 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process	g_process = {NULL, 0, 0};

int	main(
	int argc,
	char **argv,
	char **env)
{
	t_var	*var;
	char	*input;
	int		fd_read_end;

	var = init(env);
	while (1)
	{
		get_signo(0);
		rl_replace_line("", 0);
		input = readline("$> ");
		if (!input)
			exit (0);
		if (input[0])
			add_history((const char *)input);
		fd_read_end = init_command_context(var, input);
		printf("Number of commands : %d\n", var->n_cmds);
		printf("Number of redirections : %d\n", var->n_redirs);
		printf("---------------------------------------------------------------\n");
		if (var->l_arg != NULL)
			executer(var, 0, fd_read_end);
		free_command_context(var, input, fd_read_end);
	}
	return (EXIT_SUCCESS);
}

// Will cleanup a bit the code :
// TODO: function to end everything
