/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:34:59 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 03:01:15 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// *****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// *****************************************************************************
// Functions - check.c

// NOTE: Documentation
int			check_identifier(char *const str);

/*
@brief Check for a FLAG argument in the given list.

@param l_arg    List of arguments to check for the FLAG argument.
@return         Pointer to the list element containing the FLAG argument,
                or NULL if not found.
*/
t_list		*check_arg_flag(t_list *const l_arg);

// *****************************************************************************
// Functions - count.c

/*
@brief Count the number of arguments in the list.

@param l_arg   The list of arguments.
@return        Returns the count of arguments.
*/
int			count_argument(struct s_list *l_arg);

/*
@brief Count the number of commands in the list.

@param l_arg   The list of arguments.
@return        Returns the count of commands.
*/
int			count_command(struct s_list *l_arg);

/*
@brief Count the number of redirections in the list.

@param l_arg   The list of arguments.
@return        Returns the count of redirections.
*/
int			count_redirections(struct s_list *l_arg);

/*
@brief Count the number of separators in the list.

@param l_arg   The list of arguments.
@return        Returns the count of separators.
*/
int			count_separator(struct s_list *l_arg);

// *****************************************************************************
// Functions - define_*.c

/*
@brief Define the builtin commands in the command list.

@param list    Pointer to the command list.
*/
void		define_builtins(t_list **list);

/*
@brief Define the type of each element in the list.

@param list    A pointer to the list to be processed.
@return        Returns NULL.
*/
void		*define_elem(t_list **list);

/*
@brief Check if the type is a redirection or a pipe.

@param type    The argument type to check.
@return        Returns 1 if the type is a redirection or a pipe, 0 otherwise.
*/
int			r_or_p(int type);

/*
@brief Check if the type is a delimiter or RI_FILE.

@param type    The argument type to check.
@return        Returns 1 if the type is a delimiter or RI_FILE, 0 otherwise.
*/
int			delim_or_rifile(int type);

/*
@brief Define the type of elements related to redirection in the list.

@param list    The list of arguments.
*/
void		define_redir(t_list **list);

// ****************************************************************************
// Functions - error.c

/*
@brief Print an error message and set the return code.

@param err    Error message.
@param info    Additional information.
@param code    Return code.
@return             The provided return code.
*/
int			err(
				char *err,
				char *info,
				int code);

/*
@brief Print an error message with two additional information arguments
	and set the return code.

@param err        Error message.
@param info        First additional information.
@param info_2    Second additional information.
@param code        Return code.
@return                 The provided return code.
*/
int			err_d(
				char *err,
				char *info,
				char *info_2,
				int code);

/*
@brief Prints an error message and exits the program.

@param error  Error string.
@param info   Additional information string.
@param code   Error code.
*/
void		err_exit(
				char *error,
				char *info,
				int code);

// ****************************************************************************
// Functions - free.c

/*
@brief Safely frees memory.

@param ptr    Pointer to memory block.
*/
void		safe_free(void *ptr);

/*
@brief Frees command context.

@param var          Pointer to t_var structure.
@param input        Input string.
@param fd_read_end  File descriptor read end.
*/
void		free_command_context(
				t_var *var,
				char *input,
				int fd_read_end);

/**
@brief Frees up an env {key:value} pair in a t_list.

@param env Environnement variable, stored as a {key:value} pair.
*/
void		free_env(void *env);

/**
@brief Frees up the t_var variable.

@param var Variable that contains all the other useful ones.
*/
void		free_var(struct s_var *var);

/**
@brief Frees up the char** array.

@param array Regular char**.
*/
void		free_2d_char(char **array);

// *****************************************************************************
// Functions - get_*.c

/*
@brief Get the content of an argument from the list element.

@param l_arg_element   The list element containing the argument.
@return                Returns the content of the argument.
*/
char		*get_arg_content(const t_list *l_arg_element);

/*
@brief Get the type of an argument from the list element.

@param l_arg_element   The list element containing the argument.
@return                Returns the type of the argument.
*/
t_enum_type	get_arg_type(const t_list *l_arg_element);

/*
@brief Returns the number of arguments in a list.

@param l_arg  Pointer to a list of arguments.
@return             Number of arguments.
*/
int			get_number_arguments(t_list *const l_arg);

/*
@brief Returns the command start.

@param var    Pointer to t_var structure.
@return             Pointer to the start of the command.
*/
t_list		*get_cmd_start(t_var *var);

/*
@brief Returns the command end.

@param start  Pointer to the start of the command.
@return             Pointer to the end of the command.
*/
t_list		*get_cmd_end(t_list *const start);

/*
@brief Returns the current command.

@param var    Pointer to t_var structure.
@param start  Pointer to the start of the command.
@return             Pointer to the current command.
*/
t_list		*get_cmd_current(
				t_var *var,
				t_list *const start);

/*
@brief Returns the current command.

@param var    Pointer to t_var structure.
@param start  Pointer to the start of the command.
@return             Pointer to the current command.
*/
t_list		*get_next_redir_in(
				t_var *var,
				t_list *const start);

t_list		*get_next_redir_out(
				t_var *var,
				t_list *const start);

/*
@brief Get the environment key from a list element.

@param l_env_element    List element containing the environment key.
@return                 Pointer to the environment key string or NULL.
*/
char		*get_env_key(const t_list *l_env_element);

/*
@brief Get the environment value from a list element.

@param l_env_element    List element containing the environment value.
@return                 Pointer to the environment value string or NULL.
*/
char		*get_env_value(const t_list *l_env_element);

/*
@brief Search for an environment element in the list.

@param l_env            List of environment elements.
@param env_key          Key of the environment element to search for.
@return                 Pointer to the list element or NULL if not found.
*/
t_list		*search_env_elem(t_list *const l_env, char *const env_key);

/*
@brief Search for an export element in the list.

@param l_exp            List of export elements.
@param key              Key of the export element to search for.
@return                 Pointer to the list element or NULL if not found.
*/
t_list		*search_exp_elem(t_list *const l_exp, const char *key);

/**
@brief Searchs for PATH ENV variable and allocates a 2D array containing all
		paths.
@param var Variable that will contain all the other useful ones.
@return 2D array containing all PATHs.
*/
char		**get_path(t_list *const l_env);

// ****************************************************************************
// Functions - init.c

/*
@brief Initialize an environment element with the given environment string.

@param envp             Environment string in the format "KEY=VALUE".
@return                 Pointer to the initialized environment element.
*/
t_env		*init_env_element(char *envp);

/*
@brief Initialize the command context for the given input string.

@param var              Pointer to a t_var structure.
@param input            Input string to be parsed.
@return                 File descriptor for the read end of the pipe.
*/
int			init_command_context(t_var *var, char *const input);

/**
@brief Creates the t_var variable that contains all the other useful ones.
		Calls other subfunctions to build the t_lists.

@param envp 2D array storing all the ENV variables.
@return Newly created t_var variable.
*/
t_var		*init(char **envp);

// *****************************************************************************
// Functions - is.c

/*
@brief Check if the list element is a command.

@param l_arg   The list element to check.
@return        Returns 1 if the element is a command, 0 otherwise.
*/
int			is_command(t_list *l_arg);

/*
@brief Check if a list element is a redirection or a special token.

@param l_arg            List element containing the argument.
@return                 1 if the element is a redirection or token, 0 otherwise.
*/
int			is_redir_and_tokens(t_list *l_arg);

/*
@brief Check if the list element is a redirection input.

@param l_arg   The list element to check.
@return        Returns 1 if the element is a redirection input, 0 otherwise.
*/
int			is_redir_in(t_list *l_arg);

/*
@brief Check if the list element is a redirection output.

@param l_arg   The list element to check.
@return        Returns 1 if the element is a redirection output, 0 otherwise.
*/
int			is_redir_out(t_list *l_arg);

/*
@brief Check if the list element is a separator.

@param l_arg   The list element to check.
@return        Returns 1 if the element is a separator, 0 otherwise.
*/
int			is_separator(t_list *l_arg);

// *****************************************************************************
// Functions - lst_utils.c

/*
@brief Print an environment element.

@param env     The environment element to print.
*/
void		print_env_elem(void *env);

/*
@brief Print the environment element in a formatted style.

@param env              Pointer to the environment element.
*/
void		print_env_exp_format(void *env);

/*
@brief Print the export element in a formatted style.

@param exp              Pointer to the export element.
*/
void		print_exp_elem(void *exp);

/*
@brief Print an argument element.

@param arg     The argument element to print.
*/
void		print_arg_elem(void *arg);

/*
@brief Free the content of a list element.

@param content The content to be freed.
*/
void		free_lstcontent(void *content);

/*
@brief Create a copy of an argument element.

@param arg     The argument element to copy.
@return        Returns a pointer to the copied argument element.
*/
t_arg		*t_arg_cpy(void *arg);

// ****************************************************************************
// Functions - signal.c

/*
@brief Set signal handlers for SIGINT and SIGQUIT.
*/
void		get_signo(int no);

/*
@brief Hide control characters from the terminal.
*/
void		ctrl_hide(void);

/*
@brief Show control characters in the terminal.
*/
void		ctrl_show(void);

/*
@brief Ignore the SIGQUIT signal.
*/
void		set_signals_interactive(void);

/*
@brief Set signals for non-interactive mode.
*/
void		set_signals_noninteractive(void);

// ****************************************************************************
// Functions - ???.c

/*
@brief Split the input string into an array of strings using the given delimiter.

@param s        Input string to split.
@param c        Delimiter character used to split the input string.
@return         Pointer to the array of strings or NULL if the input is NULL.
*/
char		**export_split(char const *s, char c);

// ****************************************************************************
// Functions - define_redir_utils.c

int			delim_or_rifile(int type);

int			r_or_p(int type);

int			arg_is_redir(int type);

/*
@brief Reset command pointers for the given command context.

@param var      Pointer to a t_var structure.
@param start    Pointer to the starting list element.
*/
void		reset_cmd_ptrs(
				t_var *var,
				t_list *const start);

#endif	// UTILS_H
