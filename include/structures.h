/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:37:28 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 12:45:41 by aguiri           ###   ########.fr       */
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
struct s_list_cmd - List of the parsed commands.
*/
typedef struct s_list_cmd
{
	struct s_cmd		*cmd;
	struct s_list_cmd	*next;
}						t_list_cmd;

/**
struct s_env - Contains the key and linked value of an ENV variable.
*/
typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

/**
struct s_list_env - List of the parsed ENV.
*/
typedef struct s_list_env
{
	struct s_env		*env;
	struct s_list_env	*next;
}						t_list_env;

/**
struct s_paths - List containing all the paths in the PATH variable.
*/
typedef struct s_list_pth
{
	char				*str;
	struct s_list_pth	*next;
}						t_list_pth;

/**
struct s_var - Wrapper containing all the useful variables.
*/
// typedef struct s_var
// {
// 	struct s_list_env	*l_env;
// 	struct s_list_cmd	*l_cmd;
// 	struct s_list_pth	*l_pth;
// }						t_var;
typedef struct s_var
{
	struct s_list	*l_env;
	struct s_list	*l_cmd;
	struct s_list	*l_pth;
}						t_var;

/**
 * Il me faut :
 * - list chainee avec tout l'environnement
 * - list chainee avec les PATHs
 * - list chainee avec les commandes
 *		- Contenu de chaque commande
 */

#endif // STRUCTURES_H 
