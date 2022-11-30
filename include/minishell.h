/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/05 11:22:17 by aguiri           ###   ########.fr       */
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
# include "init.h"
# include "utils.h"
# include "builtins.h"

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

#endif // MINISHELL_H
