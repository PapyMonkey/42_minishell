/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:12:43 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 01:35:41 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: Documentation
char	*get_heredoc_name(void)
{
	static int	static_int;
	char		*random_name;
	char		*random_int;

	random_int = ft_itoa(static_int);
	if (!random_int)
		return (NULL);
	random_name = ft_strjoin(HEREDOC_NAME, random_int);
	if (!random_name)
		err_exit(strerror(errno), NULL, errno);
	safe_free(random_int);
	static_int++;
	return (random_name);
}

// NOTE: Documentation
static int	heredoc_evaluate_line(
	t_var *var,
	char **line,
	char *heredoc_delimiter)
{
	if (!(*line))
		return (err("warning",
				"here-document delimited by end-of-file: wanted", 0));
	if (!ft_strncmp(*line, heredoc_delimiter, ft_strlen(*line)))
		return (0);
	if (ft_strchr(*line, '$'))
	{
		*line = heredoc_split_to_expander(var, *line);
		if (!(*line))
		{
			safe_free(*line);
			return (1);
		}
	}
	return (1);
}

// NOTE: Documentation
static int	create_heredoc_file(
	t_var *var,
	char *filename,
	t_list *delim)
{
	int		fd_tmp_file;
	char	*red_line;

	fd_tmp_file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_tmp_file < 0)
	{
		err(filename, strerror(errno), errno);
		return (EXIT_CODE);
	}
	red_line = NULL;
	while (1)
	{
		set_signals_interactive();
		red_line = readline(HEREDOC_PROMPT);
		set_signals_noninteractive();
		if (!heredoc_evaluate_line(var, &red_line, get_arg_content(delim)))
			break ;
		ft_putendl_fd(red_line, fd_tmp_file);
		safe_free(red_line);
	}
	safe_free(red_line);
	close(fd_tmp_file);
	return (EXIT_SUCCESS);
}

int	redir_heredoc(t_var *var)
{
	t_list	*heredoc_delimiter;
	char	*heredoc_filename;
	int		fd_input;

	heredoc_delimiter = var->next_redir_in->next;
	if (!heredoc_delimiter)
	{
		err("syntax error near unexpected token `newline`", NULL, 2);
		return (EXIT_CODE);
	}
	heredoc_filename = get_heredoc_name();
	if (create_heredoc_file(var, heredoc_filename, heredoc_delimiter) < 0)
	{
		safe_free(heredoc_filename);
		return (EXIT_CODE);
	}
	fd_input = open(heredoc_filename, O_RDONLY);
	if (fd_input < 0)
		err_exit(heredoc_filename, strerror(errno), errno);
	safe_free(heredoc_filename);
	exec_redirect_fd(fd_input, STDIN_FILENO);
	var->next_redir_in = get_next_redir_in(var, var->next_redir_in->next);
	return (HERE_DOC);
}
