/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:34:59 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 04:05:10 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions - print.c

/**
@brief Print an env {key:value} pair in a t_list.

@param env Environnement variable, stored as a {key:value} pair.
*/
void	print_env_elem(void *env);

#endif	// UTILS_H