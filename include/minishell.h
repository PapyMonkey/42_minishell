/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/02/26 17:31:45 by bgales           ###   ########.fr       */
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
// Enum

enum{
	WORD,
	PIPE,
	HERE_DOC,
	REDIR_IN,
	APPEND,
	REDIR_OUT
};

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

t_lexer	*ft_split_args(char *str);
char	**to_split(char *str);

// ****************************************************************************
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
@brief Delete all quotes from a string.
*/
char	*del_quotes(char *split);

/**
@brief Count every word inside of a string according to the shell word cutting.
*/
int		word_count(char *str);

/**
@brief Find which elem of Enum is contained in a string and returns its number.
*/
int		enum_finder(char *str);
#endif // MINISHELL_H
