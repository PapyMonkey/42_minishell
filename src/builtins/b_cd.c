/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:25:16 by bgales            #+#    #+#             */
/*   Updated: 2023/04/07 17:59:25 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	itter_whitespace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	return (i);
}

void	b_cd(t_list **l_env, char *str)
{
	char	cwd[1024];
	char	*path;
	int		i;
	t_env	*env;
	t_list	*tmp;

	tmp = get_env_elem(*l_env, "PWD");
	env = tmp->content;
	i = itter_whitespace(str);
	while (str[i] && str[i] != ' ' && str[i] != '	')
		i++;
	if (str[i] == ' ' || str[i] == '	')
		i--;
	path = ft_substr(str, itter_whitespace(str), i);
	chdir(path);
	free(path);
	getcwd(cwd, 1024); //CREER OLDPWD
	free (env->value);
	env->value = ft_strdup(cwd);
}
