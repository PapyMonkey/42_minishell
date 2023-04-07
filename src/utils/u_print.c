/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:34:58 by aguiri            #+#    #+#             */
/*   Updated: 2023/02/25 17:20:49 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// HACK: Use get_env functions
// FIX: Change prototype to stay consistent (don't use tmp->content but just tmp)
void	print_env_elem(void *env)
{
	printf("%s=%s\n",
		(char *)((t_env *)env)->key,
		(char *)((t_env *)env)->value
		);
}

// HACK: Use get_env functions
// FIX: Change prototype to stay consistent (don't use tmp->content but just tmp)
void	print_env_exp_format(void *env)
{
	printf("declare -x %s=\"%s\"\n",
		(char *)((t_env *)env)->key,
		(char *)((t_env *)env)->value
		);
}

// FIX: Change prototype to stay consistent (don't use tmp->content but just tmp)
void	print_exp_elem(void *exp)
{
	printf("declare -x %s\n",
		(char *)exp
		);
}

// HACK: Use get_arg functions
void	print_arg_elem(void *arg)
{
	const char	*enum_c[] = {"NULL", "BUILTIN", "EXEC", "DOLLAR",
		"PIPE", "APPEND", "REDIR_OUT", "HERE_DOC", "REDIR_IN",
		"OPEN_QUOTE", "CLOSE_QUOTE", "QUOTE", "OPEN_D_QUOTE",
		"CLOSE_D_QUOTE", "D_QUOTE", "TEXT", "WHITE_SPACE", "IN_D_QUOTES",
		"OUT_D_QUOTES", "IN_QUOTES", "OUT_QUOTES", "FLAG", "ARG", "R_FILE",
		"DELIM", "RI_FILE"};

	printf("[%s - %d] = %s\n", enum_c[((t_arg *)arg)->type],
		((t_arg *)arg)->type, ((t_arg *)arg)->content);
}
