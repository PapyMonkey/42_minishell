/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:40:51 by bgales            #+#    #+#             */
/*   Updated: 2023/04/14 02:03:42 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Check if the given string starts with a quote.

@param str     The input string to check.
@param list    The list to store the quote if found.
@return        Returns 1 if a quote is found, 0 otherwise.
*/
static int	is_quote(char *str, t_list **list)
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

/*
@brief Checks if the given string is a pipe or a redirection
@param str The string to check
@param list Pointer to the list of arguments
@return 0 if not a pipe or a redirection, 1 if single character,
	2 if double characters
*/
static int	is_pipe_redir(char *str, t_list **list)
{
	t_arg	*arg;

	if (!pipe_redir_finder(str))
		return (0);
	else
	{
		arg = malloc(sizeof(t_arg));
		arg->type = pipe_redir_finder(str);
		if ((arg->type % 2))
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

/*
@brief Checks if the given string starts with a space
@param str The string to check
@param list Pointer to the list of arguments
@return 0 if not starting with a space, number of spaces otherwise
*/
static int	is_space(char *str, t_list **list)
{
	int		i;
	t_arg	*arg;

	i = -1;
	if (!ft_isspace(str[0]))
		return (0);
	while (str[++i] && ft_isspace(str[i]))
		;
	arg = malloc(sizeof(t_arg));
	arg->type = WHITE_SPACE;
	arg->content = ft_substr(str, 0, i);
	ft_lstadd_back(list, ft_lstnew(arg));
	return (i);
}

// FIX: Change the way we detect white_spaces characters
/*
@brief Checks if the given string is an argument
@param str The string to check
@param list Pointer to the list of arguments
@return 0 if not an argument, length of argument otherwise
*/
static int	is_arg(char *str, t_list **list)
{
	int		i;
	t_arg	*arg;

	i = 0;
	while (str[i] && str[i] != '\'' && str[i] != '\"' && str[i] != ' '
		&& str[i] != '	' && !pipe_redir_finder(&str[i])
		&& !alias_finder(&str[i]))
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

t_list	*struct_init(char *str, t_list *env)
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
		i += is_alias(&str[i], &ret);
	}
	if (!no_quote(&ret))
		open_close_quote(&ret);
	ret = alias_replace(&ret, env);
	return (ret);
}
