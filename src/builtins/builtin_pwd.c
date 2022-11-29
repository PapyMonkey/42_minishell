/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:45:15 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/29 19:57:51 by mgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <stdio.h>

void	builtin_pwd(char **envp)
{
	int		i;
	int		j;

	i = 0;
	while (strncmp(envp[i], "PWD", 3) != 0 && envp[i] != NULL)
		i++;
	// printf("%s\n", strtrim(envp[i], "PWD="));
	j = 3;
	while (envp[i][++j])
		printf("%c", envp[i][j]);
	printf("\n");
}
