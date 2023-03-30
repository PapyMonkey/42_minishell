/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/03/30 07:44:38 by aguiri           ###   ########.fr       */
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
# include "utils.h"
# include "builtins.h"
# include "pipex.h"
# include "expander.h"

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

/**
@brief Print on STDOUT a custom error message (errno) and exit the current
		process with exit(1).
*/
void	err_put_exit_command_not_found(char *str);

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

/**
@brief Frees up the char** array.

@param array Regular char**.
*/
void	free_2d_char(char **array);

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
t_list	*struct_init_2(t_list **list);
void	free_lstcontent(void *content);
t_arg	*t_arg_cpy(void *arg);
char	*minishell_join(char *s1, char *s2);
void	*define_elem(t_list **list);
void	*del_whitespace(t_list **list);
int		no_quote(t_list **list);
void	empty_quotes(t_list **list);
void	join_text(t_list **list);
int		no_quote(t_list **list);
int		no_whitespace(t_list *list);
t_list	*join_quotes(t_list **list);
void	*join_all(t_list **list);
int		alias_finder(char *str);
t_list	*alias_replace(t_list **list, t_list *l_env);
int		is_alias(char *str, t_list **list);
void	*open_close_quote(t_list **lst);
void	get_signo(void);

#endif // MINISHELL_H
