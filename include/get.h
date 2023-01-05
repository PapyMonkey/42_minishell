/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 03:54:08 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 05:51:15 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions

/**
@brief Searchs and points to a given element of the ENV variables.

@param l_env List of ENV variables.
@param env_key Name of the variable to be searched.
@return Pointer to the wanted element, NULL if it doesn't exist.
*/
t_list	*get_env_elem(t_list *const l_env, const char *env_key);

/**
@brief Searchs for PATH ENV variable and allocates a 2D array containing all
		paths.

@param var Variable that will contain all the other useful ones.
@return 2D array containing all PATHs.
*/
char	**get_path(t_list *const l_env);

#endif	// GET_H
