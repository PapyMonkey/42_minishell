/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:38:28 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 17:32:47 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

// *****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// *****************************************************************************
// Functions - alias_*.c

/*
@brief Replace aliases in the given list with their corresponding values.

@param list    Pointer to the list of aliases.
@param l_env   List of environment variables.
@return        A new list with aliases replaced.
*/
t_list	*alias_replace(t_list **list, t_list *l_env);

/*
@brief Check if a string has an alias.

@param str     String to check for alias.
@return        1 if alias found, 0 otherwise.
*/
int		alias_finder(char *str);

/*
@brief Check if a string has an alias and add it to the list.

@param str     String to check for alias.
@param list    Pointer to the list of aliases.
@return        Length of the alias, 0 if not found.
*/
int		is_alias(char *str, t_list **list);

/*
@brief Skip a HERE_DOC section in the list of arguments.

@param ret  Pointer to the return list.
@param ptr  Pointer to the current list position.
*/
void	here_doc_skip(t_list **ret, t_list **ptr);

/*
@brief Skip the content inside quotes in the list of arguments.

@param ret  Pointer to the return list.
@param ptr  Pointer to the current list position.
*/
void	quote_skip(t_list **ret, t_list **ptr);

// *****************************************************************************
// Functions - lexer_*.c

/*
@brief Splits arguments from a string and initializes a list with environment
variables.

@param str		The input string containing arguments.
@param env		The environment list.
@return			A pointer to the t_list containing the split arguments.
*/
t_list	*ft_split_args(char *str, t_list *env);

/*
@brief Initializes a struct based on the given string.

@param str		The string to process.
@param env		The environment list.
@return			The initialized struct.
*/
t_list	*struct_init(char *str, t_list *env);

/*
@brief Opens and closes quotes in the list.

@param lst		Pointer to the list of arguments.
@return			0 (null pointer).
*/
void	*open_close_quote(t_list **lst);

/*
@brief Initializes a struct with additional processing.

@param list		Pointer to the list of arguments.
@return			The initialized struct.
*/
t_list	*struct_init_2(t_list **list);

// *****************************************************************************
// Functions - lexer_join.c

/*
@brief Join quotes in the given list.

@param list		Pointer to the list of elements.
@return			A new list with quotes joined.
*/
t_list	*join_quotes(t_list **list);

/*
@brief Join text elements in the given list.

@param list		Pointer to the list of elements.
*/
void	join_text(t_list **list);

// *****************************************************************************
// Functions - lexer_utils_*.c

/*
@brief Join two strings and free the first one.

@param s1		First string to join.
@param s2		Second string to join.
@return			A new joined string.
*/
char	*minishell_join(char *s1, char *s2);

/*
@brief Determine the type of a pipe or redirection symbol.

@param str		String to check for pipe or redirection.
@return			Type of pipe or redirection, 0 if not found.
*/
int		pipe_redir_finder(char *str);

/*
@brief Iterate through quotes in a string.

@param str		String to iterate through.
@param c		Quote character.
@param len		Pointer to the length of the quote.
@return			Number of characters iterated.
*/
int		itter_quote(char *str, char c, int *len);

/*
@brief Check if a string has closed quotes.

@param str		String to check for closed quotes.
@return			1 if quotes are not closed, 0 otherwise.
*/
int		closed_quotes(char *str);

/*
@brief Joins all contents of the list into a single t_arg and returns a new
				list.

@param list		Pointer to the list containing t_arg elements to be joined.
@return			Returns a new list containing a single t_arg with the joined
				contents.
*/
void	*join_all(t_list **list);

/*
@brief Checks if there are no redirection or whitespace elements in the list.

@param list		The list to be checked.
@return			1 if there are no redirection or whitespace elements, 0
				otherwise.
*/
int		no_redir_no_whitespace(t_list *list);

/*
@brief Removes whitespace elements from the given list.

@param list		Pointer to the list containing t_arg elements.
@return			A new list with whitespace elements removed.
*/
t_list	*del_whitespace(t_list **list);

/*
@brief Checks if there are no quote elements in the list.

@param list		Pointer to the list containing t_arg elements.
@return			1 if there are no quote elements, 0 otherwise.
*/
int		no_quote(t_list **list);

/*
@brief Handles empty quotes in the list.

@param list		Pointer to the list containing t_arg elements.
*/
void	empty_quotes(t_list **list);

#endif // LEXER_H
