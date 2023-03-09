/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:34:58 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/09 17:03:08 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_lstcontent(void *content)
{
	t_arg *arg;
	arg = (t_arg *)content;
	free(arg->content);
	free(arg);
}

void	print_env_elem(void *env)
{
	printf("%s=%s\n",
		(char *)((t_env *)env)->key,
		(char *)((t_env *)env)->value
		);
}

void	print_arg_elem(void *arg)
{
	const char	*enum_c[] = {"NULL", "BUILTIN", "EXEC", "DOLLAR",
		"PIPE", "APPEND", "REDIR_OUT", "HERE_DOC", "REDIR_IN",
		"OPEN_QUOTE", "CLOSE_QUOTE", "QUOTE", "OPEN_D_QUOTE",
		"CLOSE_D_QUOTE", "D_QUOTE", "TEXT", "WHITE_SPACE", "IN_D_QUOTES",
		"OUT_D_QUOTES", "IN_QUOTES", "OUT_QUOTES", "FLAG", "ARG"};

	printf("[%s - %d] = %s\n", enum_c[((t_arg *)arg)->type],
		((t_arg *)arg)->type, ((t_arg *)arg)->content);
}

t_arg	*t_arg_cpy(void *arg)
{
	t_arg	*ret;
	t_arg	*ptr;

	ptr = arg;
	ret = malloc(sizeof(t_arg));
	ret->content = ft_strdup(ptr->content);
	ret->type = ptr->type;
	return (ret);
}
// void	print_char_elem(void *content)
// {
// 	printf("%s=%s\n",
// 		(char *)((t_arg *)arg)->key,
// 		(char *)((t_arg *)arg)->value
// 		);
// }