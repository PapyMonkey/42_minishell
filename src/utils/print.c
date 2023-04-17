/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:34:58 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/17 23:08:15 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_elem(void *env)
{
	printf("%s=%s\n",
		(char *)((t_env *)env)->key,
		(char *)((t_env *)env)->value
		);
}

void	print_env_exp_format(void *env)
{
	printf("declare -x %s=\"%s\"\n",
		(char *)((t_env *)env)->key,
		(char *)((t_env *)env)->value
		);
}

void	print_exp_elem(void *exp)
{
	printf("declare -x %s\n",
		(char *)exp
		);
}

void	print_arg_elem(void *arg)
{
	const char	*enum_c[] = {"NULL", "BUILTIN", "EXEC", "ARG", "FLAG",
		"DOLLAR", "TEXT", "PIPE", "WHITE_SPACE", "REDIR_IN", "APPEND",
		"REDIR_OUT", "HERE_DOC", "DELIM", "R_FILE", "RI_FILE", "QUOTE",
		"OPEN_QUOTE", "CLOSE_QUOTE", "IN_QUOTES", "OUT_QUOTES", "D_QUOTE",
		"OPEN_D_QUOTE", "CLOSE_D_QUOTE", "IN_D_QUOTES", "OUT_D_QUOTES"};

	printf("[%s - %d] = %s\n", enum_c[((t_arg *)arg)->type],
		((t_arg *)arg)->type, ((t_arg *)arg)->content);
}
