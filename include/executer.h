/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:53:00 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 03:08:09 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Functions - exec_utils.c

// TODO: Documentation
char		**exec_build_cmd(t_list *l_arg);

// TODO: Documentation
char		**exec_build_env(struct s_list *l_env);

// TODO: Documentation
void		exec_redirect_fd(
				int old_fd,
				int new_fd);

// TODO: Documentation
char		*exec_try_access(
				char *command,
				char **path);

// ****************************************************************************
// Functions - executer.c

// TODO: Documentation
void		executer(
				t_var *var,
				int index,
				int fd_old);

// ****************************************************************************
// Functions - redir_utils.c

// TODO: Documentation
void		read_and_write_to_fd(
				int fd_read,
				int fd_write);

// TODO: Documentation
void		read_and_write_to_fd_heredoc(
				int fd_read,
				int fd_write,
				const t_list *heredoc_delimiter);

// TODO: Documentation
void		read_and_write_to_fd_heredoc_v2(
				int fd_read,
				int fd_write,
				const t_list *heredoc_delimiter);

// ****************************************************************************
// Functions - redirections.c

// TODO: Documentation
int			redir_heredoc_handle(
				t_var *var,
				int fd_write);

// TODO: Documentation
int			redir_in_handle(
				t_var *var,
				int fd_write);

// TODO: Documentation
int			redir_out_handle(
				t_var *var,
				int fd_read);

#endif // EXECUTER_H
