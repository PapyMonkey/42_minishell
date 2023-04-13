/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:54:21 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/13 16:27:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

static int	redir_in(t_var *var)
{
	t_list	*file_to_open;
	int		fd_input;

	file_to_open = var->next_redir_in->next;
	if (!file_to_open)
		err_exit("syntax error near unexpected token `newline`", NULL, 2);
	fd_input = open(get_arg_content(file_to_open),
			O_RDONLY);
	if (fd_input < 0)
		err_exit(get_arg_content(file_to_open), strerror(errno), errno);
	exec_redirect_fd(fd_input, STDIN_FILENO);
	var->next_redir_in = get_next_redir_in(var, var->next_redir_in->next);
	return (REDIR_IN);
}

static char	*get_heredoc_name(void)
{
	static int	static_int;
	char		*random_name;
	char		*random_int;

	random_int = ft_itoa(static_int);
	if (!random_int)
		return (NULL);
	random_name = ft_strjoin(HEREDOC_NAME, random_int);
	if(!random_name)
		err_exit(strerror(errno), NULL, errno);
	safe_free(random_int);
	static_int++;
	return (random_name);
}

static int	evaluate_heredoc_line(
	t_var *var,
	char **line,
	char *heredoc_delimiter)
{
	if (*line == NULL)
		err_exit("warning", "here-document delimited by end-of-file: wanted",
			0);
	if (!ft_strncmp(*line, heredoc_delimiter, ft_strlen(*line)))
	{
		printf("MATCH!\n");
		return (1);
	}
	/* if (io->heredoc_quotes == 0 && ft_strchr(*line, '$'))
	{
		*line = get_expanded_var_line(data, *line);
		if (!(*line))
		{
			free_ptr(*line);
			*ret = 0;
			return (0);
		}
	} */
	return (0);
}

// void	lst_remove_and_redirect(
// 	t_list **lst,
// 	t_list *elem_to_rm,
// 	t_list *new_value,
// 	void (*del)(void*))
// {
// 	ft_lstremove(lst, elem_to_rm, del);
// 	elem_to_rm
// }

// FIX: Change the way heredoc works, broken for now
// - [ ] Substitute the values of `$VARIABLE`
static int	redir_heredoc(t_var *var)
{
	t_list	*heredoc_delimiter;
	int		fd_tmp_file;
	int		fd_input;
	char	*heredoc_filename;
	char	*red_line;

	heredoc_delimiter = var->next_redir_in->next;
	if (!heredoc_delimiter)
		err_exit("syntax error near unexpected token `newline`", NULL, 2);
	heredoc_filename = get_heredoc_name();
	fd_tmp_file = open(heredoc_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_tmp_file < 0)
		err_exit(heredoc_filename, strerror(errno), errno);
	printf("heredoc_filename : %s\n", heredoc_filename);
	red_line = NULL;
	while (1)
	{
		set_signals_interactive();
		red_line = readline(HEREDOC_PROMPT);
		set_signals_noninteractive();
		printf("red_line : %s\n", red_line);
		if (evaluate_heredoc_line(var, &red_line, get_arg_content(heredoc_delimiter)))
			break ;
		ft_putendl_fd(red_line, fd_tmp_file);
		safe_free(red_line);
	}
	safe_free(red_line);
	close(fd_tmp_file);
	fd_input = open(heredoc_filename, O_RDONLY);
	if (fd_input < 0)
		err_exit(heredoc_filename, strerror(errno), errno);
	safe_free(heredoc_filename);
	// exec_redirect_fd(fd_input, STDIN_FILENO);
	// TODO: bien enlever les elements de la liste chainee 
	//
	// ft_lstremove(&var->cmd_current, heredoc_delimiter, free_lstcontent);
	// ft_lstremove(&var->cmd_current, var->cmd_current, free_lstcontent);
	// var->next_redir_out = get_next_redir_out(var->current_arg);
	// if (!(is_command(var->cmd_current) || is_redir_in(var->cmd_current)))
	// 	var->cmd_current = get_command_or_redir_next(var->cmd_current);
	var->next_redir_in = get_next_redir_in(var, var->next_redir_in->next);
	return (HERE_DOC);
}

int	redir_in_handle(t_var *var)
{
	int	result_redirections_in;

	result_redirections_in = -1;
	while (var->next_redir_in && is_redir_in(var->next_redir_in))
	{
		if (get_arg_type(var->next_redir_in) == REDIR_IN)
			result_redirections_in = redir_in(var);
		else if (get_arg_type(var->next_redir_in) == HERE_DOC)
			result_redirections_in = redir_heredoc(var);
	}
	return (result_redirections_in);
}
