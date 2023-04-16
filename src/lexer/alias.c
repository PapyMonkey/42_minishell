/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:56:32 by bgales            #+#    #+#             */
/*   Updated: 2023/04/14 14:15:55 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@brief Handle environment value for the given argument and list.

@param arg      Pointer to the t_arg structure.
@param ret      Pointer to the list element.
@param value    Value of the environment variable.
@return         1 if environment value was handled successfully.
*/
static int	handle_env_value(t_arg *arg, t_list **ret, char *const value)
{
	free(arg->content);
	arg->content = ft_strdup(value);
	arg->type = TEXT;
	ft_lstadd_back(ret, ft_lstnew(t_arg_cpy(arg)));
	return (1);
}

/*
@brief Get environment variable value and replace the corresponding alias

@param l_env   List of environment variables
@param ptr     Pointer to the current element in the list
@param ret     Pointer to the output list
@return        1 if alias was replaced, 0 otherwise
*/
static int	get_env(
	t_list *l_env,
	t_list **ptr,
	t_list **ret)
{
	t_env	*env;
	t_arg	*arg;
	char	*tmp_itoa;
	int		tmp_return;

	arg = (*ptr)->content;
	while (l_env != NULL)
	{
		env = l_env->content;
		if (!ft_strncmp(&arg->content[1], env->key, ft_strlen(arg->content)))
			return (handle_env_value(arg, ret, env->value));
		l_env = l_env->next;
	}
	if (!ft_strncmp(&arg->content[0], "$?", ft_strlen(arg->content)))
	{
		tmp_itoa = ft_itoa(g_process.return_code);
		tmp_return = handle_env_value(arg, ret, tmp_itoa);
		safe_free(tmp_itoa);
		return (tmp_return);
	}
	return (0);
}

t_list	*alias_replace(
	t_list **list,
	t_list *l_env)
{
	t_list	*r;
	t_list	*ptr;

	ptr = *list;
	r = NULL;
	while (ptr != NULL)
	{
		if (((t_arg *)ptr->content)->type == HERE_DOC)
			here_doc_skip(&r, &ptr);
		if (ptr != NULL && ((t_arg *)ptr->content)->type == OPEN_QUOTE)
			quote_skip(&r, &ptr);
		if (ptr != NULL && ((t_arg *)ptr->content)->type == DOLLAR)
			get_env(l_env, &ptr, &r);
		else
			if (ptr != NULL)
				ft_lstadd_back(&r, ft_lstnew(t_arg_cpy((t_arg *)ptr->content)));
		if (ptr != NULL)
			ptr = ptr->next;
	}
	ft_lstclear(list, free_lstcontent);
	return (r);
}

int	alias_finder(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '?'))
		return (1);
	else
		return (0);
}

int	is_alias(char *str, t_list **list)
{
	int			i;
	t_arg		*arg;

	i = 0;
	if (str[i] == '$')
	{
		i++;
		if (!ft_isalnum(str[i]) && str[i] != '?')
			return (0);
		while (str[i])
		{
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '?'))
			{
				if (str[i] == '?' && i++ != -1)
					break ;
				i++;
			}
			arg = malloc(sizeof(t_arg));
			arg->content = ft_substr(str, 0, i);
			arg->type = DOLLAR;
			ft_lstadd_back(list, ft_lstnew(arg));
			return (i);
		}
	}
	return (0);
}
