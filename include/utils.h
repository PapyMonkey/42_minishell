/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:34:59 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/11 01:48:52 by aguiri           ###   ########.fr       */
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

// NOTE: Documentation
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

void		err(
				char *err,
				char *info,
				int code);

// NOTE: Documentation
void		err_d(
				char *err,
				char *info,
				char *info_2,
				int code);

// NOTE: Documentation
void		err_custom_exit(char *str);

/**
@brief Print on STDOUT "malloc failed" and exit the current process
		with exit(1).
*/
void		err_malloc_exit(void);

/**
@brief Print on STDOUT the corresponding error message (errno) and
		exit the current process with exit(1).
*/
void		err_put_exit(void);

/**
@brief Print on STDOUT a custom error message (errno) and exit the current
		process with exit(1).
*/
void		err_put_exit_command_not_found(char *str);

// ****************************************************************************
// Functions - free.c

// NOTE: Documentation
void		free_command_context(t_var *var, char *input, int fd_read_end);
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

// NOTE: Documentation
int			get_number_arguments(t_list *const l_arg);
/*
@brief Get the next command from the list.

@param l_arg	The list of arguments.
@return			Returns the next command from the list.
*/
t_list		*get_command_next(t_list *l_arg);

/*
@brief Get the next command or redirection from the list.

@param l_arg	The list of arguments.
@return			Returns the next command or redirection from the list.
*/
t_list		*get_command_or_redir_next(t_list *l_arg);

// NOTE: Documentation
char		*get_env_key(const t_list *l_env_element);

// NOTE: Documentation
char		*get_env_value(const t_list *l_env_element);

/**
@brief Searchs and points to a given element of the ENV variables.

@param l_env	List of ENV variables.
@param env_key	Name of the variable to be searched.
@return			Pointer to the wanted element, NULL if it doesn't exist.
*/
t_list		*search_env_elem(t_list *const l_env, char *const env_key);

// NOTE: Documentation
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

// NOTE: Documentation
/**
@brief Creates a new t_env element, splitting the provided *char on the first
		'=' character. Stores the output in a {key:value} pair.

@param envp One element of the 2D array storing all the ENV variables.
*/
t_env		*init_env_element(char *envp);

// NOTE: Documentation
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

// NOTE: Documentation
void		print_env_exp_format(void *env);

// NOTE: Documentation
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

// NOTE: Documentation
void		ctrl_hide(void);

// NOTE: Documentation
void		ctrl_show(void);

// ****************************************************************************
// Functions - ???.c

// NOTE: Documentation
char		**export_split(char const *s, char c);

#endif	// UTILS_H
