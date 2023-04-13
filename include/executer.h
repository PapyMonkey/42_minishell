/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:53:00 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 03:08:09 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions - exec_utils.c

/*
@brief Builds the command to be executed from the argument list.

@param l_arg  List containing arguments.
@return       Returns an array of arguments ready for execvp.
*/
char		**exec_build_cmd(t_list *l_arg);

/*
@brief Builds the environment array from the environment list.

@param l_env  Pointer to the environment list.
@return       Returns an array of environment variables ready for execvp.
*/
char		**exec_build_env(struct s_list *l_env);

/*
@brief Redirects a file descriptor to another.

@param old_fd File descriptor to be redirected.
@param new_fd File descriptor to be set as the new target.
*/
void		exec_redirect_fd(
				int old_fd,
				int new_fd);

/*
@brief Tries to access a command with the given path.

@param command Command to be executed.
@param path    Array of paths to search for the command.
@return        Returns the full path of the command if found, NULL otherwise.
*/
char		*exec_try_access(
				char *command,
				char **path);

// ****************************************************************************
// Functions - executer.c

// NOTE: Documentation
int			executer(
				t_var *var,
				int index,
				int fd_old);

// ****************************************************************************
// Functions - redir_*.c

// NOTE: Documentation
/*
@brief Handles REDIR_IN redirection.

@param var      Pointer to a t_var struct containing environment variables.
@param fd_write File descriptor to write the output.
@return         Returns the redirection type (REDIR_IN or REDIR_HEREDOC).
*/
int			redir_in_handle(t_var *var);

// NOTE: Documentation
/*
@brief Handles REDIR_OUT and APPEND redirection.

@param var      Pointer to a t_var struct containing environment variables.
@param fd_read  File descriptor to read the input.
@return         Returns the redirection type (REDIR_OUT or APPEND).
*/
int			redir_out_handle(t_var *var);

#endif // EXECUTER_H
