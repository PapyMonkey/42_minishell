/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:56:32 by bgales            #+#    #+#             */
/*   Updated: 2023/04/03 17:26:52 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env(t_list *l_env, t_list **ptr, t_list **ret)
{
	t_env	*env;
	t_arg	*arg;
	t_arg	*new;

	arg = (*ptr)->content;
	while (l_env != NULL)
	{
		env = l_env->content;
		if (!ft_strncmp(&arg->content[1], env->key, ft_strlen(arg->content)))
		{
			free(arg->content);
			arg->content = ft_strdup(env->value);
			arg->type = TEXT;
			ft_lstadd_back(ret, ft_lstnew(t_arg_cpy(arg)));
			return (1);
		}
		l_env = l_env->next;
	}
	return (0);
}

t_list	*alias_replace(t_list **list, t_list *l_env)
{
	t_env	*env;
	t_list	*r;
	t_list	*ptr;

	ptr = *list;
	r = NULL;
	while (ptr != NULL)
	{
		if (((t_arg *)ptr->content)->type == OPEN_QUOTE)
		{
			while (((t_arg *)ptr->content)->type != CLOSE_QUOTE)
			{
				ft_lstadd_back(&r, ft_lstnew(t_arg_cpy((t_arg *)ptr->content)));
				ptr = ptr->next;
			}
		}
		if (((t_arg *)ptr->content)->type == DOLLAR)
			get_env(l_env, &ptr, &ret);
		else
			ft_lstadd_back(&r, ft_lstnew(t_arg_cpy((t_arg *)ptr->content)));
		ptr = ptr->next;
	}
	ft_lstclear(list, free_lstcontent);
	return (r);
}

int	alias_finder(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$' && ft_isalnum(str[i + 1]))
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
		if (!ft_isalnum(str[i]))
			return (0);
		while (str[i])
		{
			while (str[i] && ft_isalnum(str[i]))
				i++;
			arg = malloc(sizeof(t_arg));
			arg->content = ft_substr(str, 0, i);
			arg->type = DOLLAR;
			ft_lstadd_back(list, ft_lstnew(arg));
			return (i);
		}
	}
	return (0);
}
