/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:37:28 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/01 18:48:39 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H 

// ****************************************************************************
// Structures

/**
 * struct s_paths - Contains all the path in the PATH environnement variable.
 */
typedef struct s_paths
{
	char			*str;
	struct s_paths	*next;
}					t_paths;

/**
 * struct s_cmd - Contains all a command related information.
 */
typedef struct s_cmd
{
	char	*name;
	char	*path;
	char	*flags;
	char	*arg;
}			t_cmd;

/**
 * struct s_cmd - Contains the list of parsed commands.
 */
typedef struct s_cmdlist
{
	struct s_cmd		*cmd;
	struct s_cmdlist	*next;
}						t_cmdlist;

/**
 * struct s_var - Contains all the path in the PATH environnement variable.
 */
typedef struct s_var
{
	t_paths	path;
	t_cmd	cmd;
}			t_var;

#endif // STRUCTURES_H 
