/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:48:45 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/06 06:01:11 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// ****************************************************************************
// Personal library

# include "structures.h"
# include "get.h"
# include "libft.h"

// ****************************************************************************
// Functions

/**
@brief Replicates the bash echo builtin command. See manual.

@param str String to be echo-ed.
*/
void	b_echo(const char *str);

/**
@brief Replicates the bash env builtin command. See manual.

@param l_env List of ENV variables.
*/
void	b_env(t_list *const l_env);

/**
@brief Exit the program properly (calls free functions)

@param var Variable that contains all the other useful ones.
*/
void	b_exit(t_var *var);

/**
@brief Replicates the bash pwd builtin command. See manual.

@param l_env List of ENV variables.
*/
void	b_pwd(t_list *const l_env);

/**
@brief Unset an ENV variable.

@param l_env List of ENV variables.
@param str Argument/input string.
*/
void	b_unset(t_list *l_env, const char *str);

// ****************************************************************************
// Functions - b_utils.c

/**
@brief Executes builtins commands if needed.

@param str Input string/command.
@param var Variable that contains all the other useful ones.
@return 1 if the given str was a builtin, otherwise 0.
*/
int		b_routine(const char *str, t_var *var);

#endif // BUILTINS_H
