/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:37:28 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/13 15:55:05 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// ****************************************************************************
// Enums

/**
enum enum_type - Contains the type of the content stored in t_arg.
*/
typedef enum enum_type
{
	BUILTIN = 1,
	EXEC,
	ARG,
	FLAG,
	DOLLAR,
	TEXT,
	WHITE_SPACE,
	PIPE,
	REDIR_IN,
	APPEND,
	REDIR_OUT,
	HERE_DOC,
	DELIM,
	R_FILE,
	RI_FILE,
	QUOTE,
	OPEN_QUOTE,
	CLOSE_QUOTE,
	IN_QUOTES,
	OUT_QUOTES,
	D_QUOTE,
	OPEN_D_QUOTE,
	CLOSE_D_QUOTE,
	IN_D_QUOTES,
	OUT_D_QUOTES,
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

	struct s_list		*cmd_start;
	struct s_list		*cmd_end;
	struct s_list		*cmd_current;
	struct s_list		*next_redir_in;
	struct s_list		*next_redir_out;

	int					n_cmds;

	char				**command_array;
}						t_var;

#endif // STRUCTURES_H
