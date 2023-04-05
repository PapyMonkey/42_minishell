/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:34:59 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:44:07 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions - count.c

// TODO: Documentation
int		count_argument(struct s_list *l_arg);

// TODO: Documentation
int		count_command(struct s_list *l_arg);

// TODO: Documentation
int		count_separator(struct s_list *l_arg);

// ****************************************************************************
// Functions - get...

// TODO: Documentation
char		*get_arg_content(t_list *l_arg_element);

// TODO: Documentation
t_enum_type	get_arg_type(t_list *l_arg_element);

// TODO: Documentation
t_list		*get_command_next(t_list *l_arg);

// TODO: Documentation
t_list		*get_previous_sep(t_var *var, int index);

/**
@brief Searchs and points to a given element of the ENV variables.

@param l_env List of ENV variables.
@param env_key Name of the variable to be searched.
@return Pointer to the wanted element, NULL if it doesn't exist.
*/
t_list		*get_env_elem(t_list *const l_env, const char *env_key);

/**
@brief Searchs for PATH ENV variable and allocates a 2D array containing all
		paths.

@param var Variable that will contain all the other useful ones.
@return 2D array containing all PATHs.
*/
char		**get_path(t_list *const l_env);

// ****************************************************************************
// Functions - is...

// TODO: Documentation
int			is_command(t_list *l_arg);

// TODO: Documentation
int			is_separator(t_list *l_arg);

// ****************************************************************************
// Functions - print.c

/**
@brief Print an env {key:value} pair in a t_list.

@param env Environnement variable, stored as a {key:value} pair.
*/
void	print_env_elem(void *env);

// TODO: Documentation
void	print_arg_elem(void *arg);

#endif	// UTILS_H
