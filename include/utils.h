/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:34:59 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/02 15:26:53 by bgales           ###   ########.fr       */
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

// TODO: Doc
void	print_arg_elem(void *arg);

#endif	// UTILS_H
