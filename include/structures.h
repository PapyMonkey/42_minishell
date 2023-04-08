/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:37:28 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/07 23:17:59 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// ****************************************************************************
// Enums

/**
enum enum_type- Contains the type of the content stored in t_arg.
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
	ARG,
	R_FILE,
	DELIM,
	RI_FILE,
}	t_enum_type;

// ****************************************************************************
// Structures

// NOTE: Documentation
typedef struct s_process
{
	char	*pwd;
	int		pid;
	int		return_code;
}			t_process;

extern t_process	g_process;

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

/*
@brief Struct representing an argument.

@var content    The content of the argument.
@var type       The type of the argument (from the t_enum_type enumeration).
*/
typedef struct s_arg
{
	char		*content;
	t_enum_type	type;
}				t_arg;

/**
struct s_var - Wrapper containing all the useful variables.
*/
typedef struct s_var
{
	struct s_list		*l_env;
	struct s_list		*l_exp;
	struct s_list		*l_arg;
	struct s_list		*current_arg;
	int					n_cmds;
	int					n_redirs;
	char				**command_array;
}						t_var;

#endif // STRUCTURES_H
