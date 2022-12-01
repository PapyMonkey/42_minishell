/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:19:54 by aguiri            #+#    #+#             */
/*   Updated: 2022/05/31 16:32:15 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_infile_read(int *fd, int fd_infile)
{
	char	*out;

	out = ft_get_next_line(fd_infile);
	if (out)
	{
		if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
			ft_error_put_exit();
		while (out)
		{
			out = ft_get_next_line(fd_infile);
			if (out)
				if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
					ft_error_put_exit();
		}
		if (write(fd[WRITE_END], "\0", 1) == -1)
			ft_error_put_exit();
	}
	free(out);
}

void	ft_pipex_outfile_write(int *fd, int fd_outfile)
{
	int		i;
	char	*out;

	i = 0;
	out = ft_get_next_line(fd[READ_END]);
	if (out)
	{
		if (write(fd_outfile, out, ft_strlen(out)) == -1)
			ft_error_put_exit();
		while (out)
		{
			out = ft_get_next_line(fd[READ_END]);
			if (out)
				if (write(fd_outfile, out, ft_strlen(out)) == -1)
					ft_error_put_exit();
			i++;
		}
		exit(EXIT_SUCCESS);
	}
	free(out);
}

void	ft_pipex_infile(size_t i, int *fd, t_cmds cmds)
{
	char	*path;
	int		fd_infile;

	path = ft_join_pwd_path(i, cmds);
	fd_infile = open(path, O_RDONLY);
	free(path);
	if (fd_infile == -1)
		ft_error_put_exit();
	close(fd[READ_END]);
	ft_pipex_infile_read(fd, fd_infile);
	close(fd[WRITE_END]);
	close(fd_infile);
	exit(EXIT_SUCCESS);
}

void	ft_pipex_outfile(size_t i, int *fd, t_cmds cmds)
{
	char	*path;
	int		fd_outfile;

	path = ft_join_pwd_path(i, cmds);
	if (!ft_strncmp(cmds.args[1], HDOC, ft_strlen(HDOC)))
		fd_outfile = open(path, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd_outfile = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	free(path);
	if (fd_outfile == -1)
		ft_error_put_exit();
	close(fd[WRITE_END]);
	ft_pipex_outfile_write(fd, fd_outfile);
	close(fd[READ_END]);
	close(fd_outfile);
	exit(EXIT_SUCCESS);
}
