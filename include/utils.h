/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:34:59 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 17:40:25 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions - get_path.c

/**
@brief Build and alloc (malloc) a 2D array containing paths from the PATH
		ENV variable.

@param var Variable that will contain all the other useful ones.
@return 2D array containing paths.
*/
char	**get_path(t_var *var);

#endif	// UTILS_H
