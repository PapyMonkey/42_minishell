/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/30 10:46:07 by aguiri           ###   ########.fr       */
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
# include "builtins.h"

// ****************************************************************************
// Structures

typedef struct s_paths
{
	char			*str;
	struct s_paths	*next;
}					t_paths;

typedef struct s_cmd
{
	char	*cmdpath;
	char	*cmd;
	char	*flags;
	char	*arg;
}			t_cmd;


// ****************************************************************************
// Functions

int		get_path(char *env[], t_paths *hpaths);
int		search_path(t_paths *hpaths, t_cmd *cmd, char *str);
int		exec_cmd(t_cmd *cmd, char *av[], char *env[]);
char	**ft_split(const char *str, char sep);

#endif
