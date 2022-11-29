/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/29 15:49:08 by mgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_paths
{
	char			*str;
	struct s_paths	*next;
}					t_paths;

typedef struct s_cmd
{
	char	*cmdpath;
}			t_cmd;

int		get_path(char *env[], t_paths *hpaths);
int		search_path(t_paths *hpaths, t_cmd *cmd, char *str);
int		exec_cmd(t_cmd *cmd, char *av[], char *env[]);
char	**ft_split(const char *str, char sep);

#endif