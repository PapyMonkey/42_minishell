/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:40:51 by bgales            #+#    #+#             */
/*   Updated: 2023/03/08 17:02:12 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char *str, t_list **list)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (str[0] == '\'')
		arg->type = QUOTE;
	else if (str[0] == '\"')
		arg->type = D_QUOTE;
	else
	{
		free (arg);
		return (0);
	}
	arg->content = ft_substr(str, 0, 1);
	ft_lstadd_back(list, ft_lstnew(arg));
	return (1);
}

int	is_pipe_redir(char *str, t_list **list)
{
	t_arg	*arg;

	if (!pipe_redir_finder(str))
		return (0);
	else
	{
		arg = malloc(sizeof(t_arg));
		arg->type = pipe_redir_finder(str);
		if (!(arg->type % 2))
		{
			arg->content = ft_substr(str, 0, 1);
			ft_lstadd_back(list, ft_lstnew(arg));
			return (1);
		}
		else
		{
			arg->content = ft_substr(str, 0, 2);
			ft_lstadd_back(list, ft_lstnew(arg));
			return (2);
		}
	}
}

int	is_space(char *str, t_list **list)
{
	int		i;
	t_arg	*arg;

	i = -1;
	if (str[0] != ' ' && str[0] != '	')
		return (0);
	while (str[++i] && (str[i] == ' ' || str[i] == '	'))
		;
	arg = malloc(sizeof(t_arg));
	arg->type = WHITE_SPACE;
	arg->content = ft_substr(str, 0, i);
	ft_lstadd_back(list, ft_lstnew(arg));
	return (i);
}

int	is_arg(char *str, t_list **list)
{
	int		i;
	t_arg	*arg;

	i = 0;
	while (str[i] && str[i] != '\'' && str[i] != '\"' && str[i] != ' '
		&& str[i] != '	' && !pipe_redir_finder(str))
		i++;
	if (!i)
		return (i);
	else
	{
		arg = malloc(sizeof(t_arg));
		arg->type = TEXT;
		arg->content = ft_substr(str, 0, i);
		ft_lstadd_back(list, ft_lstnew(arg));
	}
	return (i);
}

t_list	*struct_init(char *str)
{
	int		i;
	int		c;
	t_list	*ret;
	t_arg	*arg;

	ret = NULL;
	i = 0;
	while (str[i])
	{
		i += is_pipe_redir(&str[i], &ret);
		i += is_quote(&str[i], &ret);
		i += is_space(&str[i], &ret);
		i += is_arg(&str[i], &ret);
	}
	ret = struct_init_2(&ret);
	ft_lstclear(&ret, free_lstcontent);
	return (ret);
}
