/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:37:28 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 17:43:34 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H 

// ****************************************************************************
// Structures

/**
struct s_cmd - Contains all a command related information.
*/
typedef struct s_cmd
{
	char	*name;
	char	*path;
	char	*flags;
	char	*arg;
}			t_cmd;

/**
struct s_env - Contains the key and linked value of an ENV variable.
*/
typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

/**
struct s_var - Wrapper containing all the useful variables.
*/
typedef struct s_var
{
	struct s_list	*l_env;
	struct s_list	*l_cmd;
}					t_var;

#endif // STRUCTURES_H 
