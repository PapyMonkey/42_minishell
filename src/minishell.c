/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:09 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/09 14:44:30 by bgales           ###   ########.fr       */
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
		ctrl_hide();
		get_signo(0);
		rl_replace_line("", 0);
		input = readline("$> ");
		if (!input)
			break ;
		if (input[0])
			add_history((const char *)input);
		ctrl_show();
		get_signo(1);
		fd_read_end = init_command_context(var, input);
		// ft_lstiter(var->l_arg, *print_arg_elem);
		// printf("Number of commands : %d\n", var->n_cmds);
		// printf("Number of redirections : %d\n", var->n_redirs);
		// printf("---------------------------------------------------------------\n");
		if (var->l_arg != NULL)
			executer(var, 0, fd_read_end);
		free_command_context(var, input, fd_read_end);
	}
	write(1, "exit\n", 5);
	return (EXIT_SUCCESS);
}
