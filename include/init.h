/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:27:52 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 17:56:22 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H 

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions

/**
@brief Creates the t_list that contains all the parsed ENV variables.

@param var Variable that will contain all the other useful ones.
@param envp 2D array storing all the ENV variables.
*/
void	init_env(struct s_var *var, char **envp);

/**
@brief Creates the t_var variable that contains all the other useful ones.
		Calls other subfunctions to build the t_lists.

@param envp 2D array storing all the ENV variables.
@return Newly created t_var variable.
*/
t_var	*init(char **envp);

#endif	// INIT_H
