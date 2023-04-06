/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/06 16:43:30 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h> 
# include <sys/ioctl.h>
# include <stdio.h>
# include <fcntl.h> 
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>

// ****************************************************************************
// Macros

# define WRITE_END 1
# define READ_END 0
# define BUFFER_SIZE 4096

// ****************************************************************************
// Personal library

# include "libft.h"

# include "builtins.h"
# include "executer.h"
# include "init.h"
# include "lexer.h"
# include "utils.h"
# include "structures.h"

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
// Functions - signal.c

// TODO: Documentation
void	get_signo(void);

#endif // MINISHELL_H
