/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:38:28 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 17:56:35 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H 

// *****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// *****************************************************************************
// Functions - alias.c

// TODO: Documentation
t_list	*alias_replace(t_list **list, t_list *l_env);

// TODO: Documentation
int		alias_finder(char *str);

// TODO: Documentation
int		is_alias(char *str, t_list **list);

// *****************************************************************************
// Functions - lexer_*.c

// TODO: Documentation
t_list	*ft_split_args(char *str, t_list *env);

/*
@brief Initializes a struct based on the given string
@param str The string to process
@param env The environment list
@return The initialized struct
*/
t_list	*struct_init(char *str, t_list *env);

/*
@brief Opens and closes quotes in the list
@param lst Pointer to the list of arguments
@return 0 (null pointer)
*/
void	*open_close_quote(t_list **lst);

/*
@brief Initializes a struct with additional processing
@param list Pointer to the list of arguments
@return The initialized struct
*/
t_list	*struct_init_2(t_list **list);

// *****************************************************************************
// Functions - lexer_join.c

// TODO: Documentation
t_list	*join_quotes(t_list **list);

// TODO: Documentation
void	join_text(t_list **list);

// *****************************************************************************
// Functions - lexer_utils_*.c

// TODO: Documentation
char	*minishell_join(char *s1, char *s2);

// TODO: Documentation
int		pipe_redir_finder(char *str);

// TODO: Documentation
/**
@brief Itterate to the next quote in char* and returns the len to get to it.
@param char*  string we'll search in@param char char to
itterate to inside the char*.
@param len norm purposes.
*/
int		itter_quote(char *str, char c, int *len);

// TODO: Documentation
/**
@brief Check for unclosed_quotes in char*.
*/
int		closed_quotes(char *str);

// TODO: Documentation
void	*join_all(t_list **list);

// TODO: Documentation
int		no_redir_no_whitespace(t_list *list);

// TODO: Documentation
t_list	*del_whitespace(t_list **list);

// TODO: Documentation
int		no_quote(t_list **list);

// TODO: Documentation
void	empty_quotes(t_list **list);

#endif // LEXER_H
