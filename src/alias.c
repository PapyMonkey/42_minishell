/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:56:32 by bgales            #+#    #+#             */
/*   Updated: 2023/03/16 13:57:51 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	alias_replace(t_list **list, t_env *env)
// {
// 	t_list	*ptr;
// 	t_arg	*arg;

// 	ptr = *list;
// 	while (ptr != NULL)
// 	{
// 		arg = ptr->content;
// 		if (arg->content[0] == '$')
// 		{
// 			while (env != NULL && ft_strncmp(arg->content, env->key,
// 					ft_strlen(arg->content)) != 0)
// 				env = env->next;
// 			if (env == NULL)
// 				ft_lstdelone(ptr, free_lstcontent);
// 			else
// 			{
// 				free (arg->content);
// 				arg->content = ft_strdup(env->value);
// 			}
// 		}
// 		ptr = ptr->next;
// 	}
// }

int	alias_finder(char c)
{
	if (c == '$')
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
