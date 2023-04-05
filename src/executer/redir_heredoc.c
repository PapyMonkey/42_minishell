/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:56:51 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/06 01:18:16 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	ft_pipex_here_doc(size_t i, int *fd, t_cmds cmds)
// {
// 	char	*limiter;
// 	char	*out;

// 	limiter = ft_strjoin(cmds.args[i + 1], "\n");
// 	out = ft_get_next_line(STDIN_FILENO);
// 	if (!out)
// 		err_put_exit();
// 	while (ft_strncmp(out, limiter, ft_strlen(limiter)))
// 	{
// 		if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
// 			ft_error_put_exit();
// 		out = ft_get_next_line(STDIN_FILENO);
// 	}
// 	free(limiter);
// 	free(out);
// 	close(fd[WRITE_END]);
// 	exit(EXIT_SUCCESS);
// }
