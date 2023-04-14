/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:53:00 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 02:42:01 by aguiri           ###   ########.fr       */
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
/*
@brief Execute a command with a specified path.

@param var    The t_var structure containing the command and environment.
@param env    The environment variables.
@return             The exit status of the command execution.
*/
int			execute_command_with_path(
				t_var *var,
				char **env);

// ****************************************************************************
// Functions - executer.c

/*
@brief Execute the commands in the pipeline.

@param var                The t_var structure containing the command.
@param index              The index of the command in the pipeline.
@param fd_parent     The file descriptor of the parent process.
@return             The exit status of the command execution.
*/
int			executer(
				t_var *var,
				int index,
				int fd_old);

// ****************************************************************************
// Functions - redir_*.c

/*
@brief Handles input redirection.

@param var    A pointer to a t_var structure.
@return           EXIT_CODE on error, REDIR_IN on success.
*/
int			redir_in_handle(t_var *var);

/*
@brief Handles output redirection.

@param var    A pointer to a t_var structure.
@return           EXIT_CODE on error, REDIR_OUT or APPEND on success.
*/
int			redir_out_handle(t_var *var);

/*
@brief Handles heredoc input redirection.

@param var    A pointer to a t_var structure.
@return           EXIT_CODE on error, HERE_DOC on success.
*/
int			redir_heredoc(t_var *var);

/*
@brief Splits a line and expands variables in each word.

@param var    A pointer to a t_var structure.
@param line   The line to be split and expanded.
@return           The modified line with expanded variables.
*/
char		*heredoc_split_to_expander(
				t_var *var,
				char *line);

#endif // EXECUTER_H
