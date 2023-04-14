/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:36:19 by mgerbaud          #+#    #+#             */
/*   Updated: 2023/04/06 16:43:30 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h> 
# include <sys/stat.h> 
# include <sys/ioctl.h>
# include <stdio.h>
# include <fcntl.h> 
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>

// ****************************************************************************
// Macros

# define WRITE_END 1
# define READ_END 0
# define EXIT_CODE 999999
# define BUFFER_SIZE 4096
# define SHELL_NAME "minishell"
# define HEREDOC_NAME "/tmp/.minishell_hd_"
# define READLINE_PROMPT "(minishell)$> "
# define HEREDOC_PROMPT ">"

// ****************************************************************************
// Personal library

# include "libft.h"

// ****************************************************************************

# include "builtins.h"
# include "executer.h"
# include "lexer.h"
# include "utils.h"
# include "structures.h"

#endif // MINISHELL_H
