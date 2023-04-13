/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:48:45 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/07 23:24:13 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions

// NOTE: Generate documentation
int		b_cd(t_var *var);

// NOTE: Generate documentation
/**
@brief Replicates the bash echo builtin command. See manual.

@param str String to be echo-ed.
*/
int		b_echo(t_var *const var);

// NOTE: Generate documentation
/**
@brief Replicates the bash env builtin command. See manual.

@param l_env List of ENV variables.
*/
int		b_env(t_var *const var);

// NOTE: Generate documentation
/**
@brief Exit the program properly (calls free functions)

@param var Variable that contains all the other useful ones.
*/
int		b_exit(t_var *var);

// NOTE: Generate documentation
int		b_export(t_var *var);

// NOTE: Generate documentation
/**
@brief Replicates the bash pwd builtin command. See manual.

@param l_env List of ENV variables.
*/
int		b_pwd(t_var *const var);

// NOTE: Generate documentation
/**
@brief Unset an ENV variable.

@param l_env List of ENV variables.
@param str Argument/input string.
*/
int		b_unset(t_var *var);

// ****************************************************************************
// Functions - b_utils.c

// NOTE: Generate documentation
int		b_routine(t_var *var);

// NOTE: Generate documentation
int		effective_exit(t_var *var);

#endif // BUILTINS_H
