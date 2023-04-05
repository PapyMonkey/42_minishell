/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:53:00 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 07:42:39 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h> 
# include <errno.h> 
# include <sys/types.h> 
# include <sys/wait.h> 

# define WRITE_END 1
# define READ_END 0
# define HDOC "here_doc"

// ****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// ****************************************************************************
// Structures

/**
 * @brief		Contains the commands and paths of pipex program.
 */
typedef struct s_cmds {
	size_t	args_nb;
	char	**args;
	char	**path;
	char	**envp;
	char	*pwd;
}			t_cmds;

// ****************************************************************************
// Functions - pipex_io.c

/**
 * @brief			Read the content of a file and write it into a pipe's
 * 					WRITE_END.
 * 
 * @param fd		Pipe's file descriptor.
 * @param fd_infile	File's file descriptor.
 */
void		ft_pipex_infile_read(int *fd, int fd_infile);

/**
 * @brief			Read the content of a pipe's READ_END and write it into
 * 					a file.
 * 
 * @param fd		Pipe's file descriptor.
 * @param fd_infile	File's file descriptor.
 */
void		ft_pipex_outfile_write(int *fd, int fd_outfile);

void		ft_pipex_infile(size_t i, int *fd, t_cmds cmds);

void		ft_pipex_outfile(size_t i, int *fd, t_cmds cmds);

// ****************************************************************************
// Functions - pipex_path.c

/**
 * @brief			Check if the given ENV variable contains the PATH variable.
 * 
 * @param envp		2D array storing all the environment variables.
 * @return			EXIT_SUCCESS if true, else EXIT_FAILURE.
 */
int			pipe_is_path(char **envp);

/**
 * @brief			Get the PATH variable from the "envp" (environment
 * 					variable) main()'s third argument.
 * 
 * @param envp		2D array storing all the environment variables.
 * @return			2D array containing all paths from the PATH variable.
 */
char		**ft_split_path(char **envp);

/**
 * @brief			Get the PWD (current working directory) from the
 * 					"envp" (environment variable) main()'s third argument.
 * 
 * @param envp		2D array storing all the environment variables.
 * @return			String containing the absolute path to the working
 * 					directory.
 */
char		*ft_get_pwd(char **envp);

char		*ft_join_pwd_path(size_t i, t_cmds cmds);

char		*ft_exec_access(char *command, char **path);

// ****************************************************************************
// Functions - pipex_utils.c

t_cmds		ft_pipex_construct(int argc, char **argv, char **envp);

void		ft_pipex_deconstruct(t_cmds cmds);

void		exec_redirect_fd(int old_fd, int new_fd);

char		**build_env_array(struct s_list *l_env);

void		executor_v2(t_var *var, int index, int fd_old);

// TODO: Documentation
char		**exec_build_cmd(t_list *l_arg);

#endif
