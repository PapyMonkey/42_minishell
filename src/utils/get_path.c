/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:45:15 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/30 11:41:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_pwd(char **envp)
{
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PWD", 3) != 0 && envp[i] != NULL)
		i++;
    ft_printf("%s\n", ft_strtrim(envp[i], "PWD="));
}
