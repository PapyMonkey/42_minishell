/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:07:04 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/11 16:48:43 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_here_doc(size_t i, int *fd, t_cmds cmds)
{
	char	*limiter;
	char	*out;

	limiter = ft_strjoin(cmds.args[i + 1], "\n");
	out = ft_get_next_line(STDIN_FILENO);
	if (!out)
		ft_error_put_exit();
	while (ft_strncmp(out, limiter, ft_strlen(limiter)))
	{
		if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
			ft_error_put_exit();
		out = ft_get_next_line(STDIN_FILENO);
	}
	free(limiter);
	free(out);
	close(fd[WRITE_END]);
	exit(EXIT_SUCCESS);
}
