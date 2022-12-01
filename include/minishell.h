/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/01 18:40:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>

// ****************************************************************************
// Personal library

# include "libft.h"

# include "structures.h"
# include "builtins.h"

// ****************************************************************************
// Functions

int		get_path(char *env[], t_paths *hpaths);
int		search_path(t_paths *hpaths, t_cmd *cmd, char *str);
int		exec_cmd(t_cmd *cmd, char *av[], char *env[]);
char	**ft_split(const char *str, char sep);

#endif // MINISHELL_H
