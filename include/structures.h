/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:37:28 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:43:48 by aguiri           ###   ########.fr       */
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
enum enum_type- Contains the type of the content stored in t_arg.
*/
/**
* Useful types for executor :
* - BUILTIN
* - EXEC
* - TEXT
* - WHITE_SPACE
* - FLAG
* - ARG
*/
typedef enum enum_type
{
	BUILTIN = 1,
	EXEC,
	DOLLAR,
	PIPE,
	APPEND,
	REDIR_OUT,
	HERE_DOC,
	REDIR_IN,
	OPEN_QUOTE,
	CLOSE_QUOTE,
	QUOTE,
	OPEN_D_QUOTE,
	CLOSE_D_QUOTE,
	D_QUOTE,
	TEXT,
	WHITE_SPACE,
	IN_D_QUOTES,
	OUT_D_QUOTES,
	IN_QUOTES,
	OUT_QUOTES,
	FLAG,
	ARG
}	t_enum_type;

/**
struct s_env - Contains the key and linked value of an ENV variable.
*/
typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

// TODO: Documentation
typedef struct s_arg
{
	char		*content;
	t_enum_type	type;
}				t_arg;

// TODO: Documentation
typedef struct s_cmd_table
{
	struct s_list	*cmd_ptr;
	char			**cmd_str;
}					t_cmd_table;

/**
struct s_var - Wrapper containing all the useful variables.
*/
typedef struct s_var
{
	struct s_list		*l_env;
	struct s_list		*l_exp;
	struct s_list		*l_arg;
	struct s_list		*sep_last;
	int					sep_count;
	struct s_cmd_table	*table_cmd;
	int					n_cmds;
}						t_var;

#endif // STRUCTURES_H
