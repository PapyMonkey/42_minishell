/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 02:29:55 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void close_fds(
	int fd_in,
	int fd_out)
{
    if (fd_in != -1)
        close(fd_in);
    if (fd_out != -1 && fd_out != STDOUT_FILENO)
        close(fd_out);
}

static void execute_cmd(
	int n_cmds,
	int fd_in,
	int fd_out,
	t_var *var)
{
    if (fd_out == -1)
        fd_out = STDOUT_FILENO;
    executor(n_cmds, fd_in, fd_out, var);
}

static void handle_file_redirections(
	t_enum_type type,
	t_list *tmp,
	int *fd_in,
	int *fd_out)
{
    int flags;
    int *fd_ptr;
    tmp = tmp->next;

    if (tmp)
    {
        t_arg *filename_arg = (t_arg *)tmp->content;

        if (type == REDIR_IN)
        {
            flags = O_RDONLY;
            fd_ptr = fd_in;
        }
        else if (type == REDIR_OUT)
        {
            flags = O_WRONLY | O_CREAT | O_TRUNC;
            fd_ptr = fd_out;
        }
        else // APPEND
        {
            flags = O_WRONLY | O_CREAT | O_APPEND;
            fd_ptr = fd_out;
        }

        if (*fd_ptr != -1)
            close(*fd_ptr);
        *fd_ptr = open(filename_arg->content, flags, 0644);
        if (*fd_ptr == -1)
            err_put_exit();
    }
}

static void handle_pipe_redirection(
	int *fd_old,
	t_list *tmp)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
        err_put_exit();

    executor(0, *fd_old, pipefd[WRITE_END], var);
    close(pipefd[WRITE_END]);
    *fd_old = pipefd[READ_END];
}

static t_list *handle_redirections(
	t_list *tmp,
	int *fd_old,
	int *fd_in,
	int *fd_out)
{
    t_arg *current_arg;

    while (tmp && !is_next_cmd(((t_arg *)tmp->content)->type))
    {
        current_arg = (t_arg *)tmp->content;
        if (current_arg->type == PIPE)
        {
            handle_pipe_redirection(fd_old, tmp);
        }
        else if (current_arg->type == REDIR_IN || current_arg->type == REDIR_OUT || current_arg->type == APPEND)
        {
            handle_file_redirections(current_arg->type, tmp, fd_in, fd_out);
        }
        tmp = tmp->next;
    }

    return tmp;
}

void parse_and_exec(t_var *var)
{
    t_list	*tmp;
	t_list	*start_exec;
	int		fd_old;
	int		fd_in;
	int		fd_out;

	tmp = var->l_arg;
    while (tmp)
    {
        if (((t_arg *)(tmp->content))->type == EXEC)
        {
            start_exec = tmp;
            fd_old = STDIN_FILENO;
            fd_in = -1;
			fd_out = -1;
            tmp = handle_redirections(tmp, &fd_old, &fd_in, &fd_out);
            execute_cmd(var->n_cmds, fd_old, fd_out, var);
            close_fds(fd_in, fd_out);
        }
        tmp = tmp->next;
    }
}


// Si il y a une next commande, on definit les fd sur les sorties correspondantes
// Sorties et entrees standard sinon.
//
// Compter le nombre de commandes pour savoir combien de process on a besoin
