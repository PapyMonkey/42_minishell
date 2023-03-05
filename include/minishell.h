/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/03/03 13:34:23 by bgales           ###   ########.fr       */
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
# include <signal.h>
# include <termios.h>

// ****************************************************************************
// Personal library

# include "libft.h"

# include "structures.h"
# include "init.h"
# include "get.h"
# include "utils.h"
# include "builtins.h"

// ****************************************************************************
// Structures

struct s_lexer
{
	char			*value;
	int				type;
	struct s_lexer	*next;
};
typedef struct s_lexer	t_lexer;

// ****************************************************************************
// Functions - error.c

/**
@brief Print on STDOUT "malloc failed" and exit the current process
		with exit(1).
*/
void	err_malloc_exit(void);

/**
@brief Print on STDOUT the corresponding error message (errno) and
		exit the current process with exit(1).
*/
void	err_put_exit(void);

// ****************************************************************************
// Functions - free.c

/**
@brief Frees up an env {key:value} pair in a t_list.

@param env Environnement variable, stored as a {key:value} pair.
*/
void	free_env(void *env);

/**
@brief Frees up the t_var variable.

@param var Variable that contains all the other useful ones.
*/
void	free_var(struct s_var *var);

// ****************************************************************************
// Functions - lexer.c

/**
@brief Split char * according to the shell word cutting.
*/
t_list	*ft_split_args(char *str);

// Functions - lexer_utils.c

/**
@brief Check for unclosed_quotes in char*.
*/
int		closed_quotes(char *str);

/**
@brief Itterate to the next quote in char* and returns the len to get to it.
@param char*  string we'll search in@param char char to
itterate to inside the char*.
@param len norm purposes.
*/
int		itter_quote(char *str, char c, int *len);

/**
@brief Find which elem of Enum is contained in a string and returns its number.
*/
int		pipe_redir_finder(char *str);
/**
@brief Itterate to the next Enum member found in char * and returns
the len to get to it.
*/
int		itter_enum(char *str);

// t_list	*struct_init(char **split);
t_list	*struct_init(char *str);
#endif // MINISHELL_H
