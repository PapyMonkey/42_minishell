/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:48:45 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/11/30 16:34:45 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// ****************************************************************************
// Personal library

# include "libft.h"

// ****************************************************************************
// Functions

void	b_echo(const char *str);

void	b_env(const char **envp);

void	b_pwd(const char **envp);

// ****************************************************************************
// Functions - b_utils.c

int		b_routine(const char *str, const char **envp);

#endif // BUILTINS_H
