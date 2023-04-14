/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:48:45 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/14 03:01:22 by aguiri           ###   ########.fr       */
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

/*
@brief Built-in command: cd.

@param var     Variable structure.
@return             Exit status.
*/
int		b_cd(t_var *var);

/*
@brief Built-in command: echo.

@param var     Variable structure.
@return             Exit status.
*/
int		b_echo(t_var *const var);

/*
@brief Built-in command: env.

@param var     Variable structure.
@return             Exit status.
*/
int		b_env(t_var *const var);

/*
@brief Built-in command: exit.

@param var     Variable structure.
@return             Exit status.
*/
int		b_exit(t_var *var);

/*
@brief Built-in command: export.

@param var     Variable structure.
@return             Exit status.
*/
int		b_export(t_var *var);

/*
@brief Prints the current working directory.

@param var    A pointer to a t_var structure.
@return           EXIT_SUCCESS on success.
*/
int		b_pwd(t_var *const var);

/*
@brief Unset environment variable.

@param var    Pointer to a t_var structure.
@return             EXIT_SUCCESS if successful, error code if an error occurs.
*/
int		b_unset(t_var *var);

// ****************************************************************************
// Functions - b_utils.c

/*
@brief Executes built-in commands.

@param var    A pointer to a t_var structure.
@return           EXIT_SUCCESS on success.
*/
int		b_routine(t_var *var);

/*
@brief Exit program with the effective exit.

@param var     Variable structure.
@return             Exit status.
*/
int		effective_exit(t_var *var);

#endif // BUILTINS_H
