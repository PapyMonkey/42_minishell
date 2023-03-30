/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/30 02:48:25 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void fork_and_exec_command(t_cmd *cmd, t_var *var)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        exec_command(cmd->path, cmd->flags, cmd->arg, var);
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

void fork_and_exec_command(t_cmd *cmd, t_var *var)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        exec_command(cmd->path, cmd->flags, cmd->arg, var);
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

// handle machin

t_cmd get_next_command(t_list **current_arg, t_var *var)
{
    t_cmd cmd;

    init_cmd(&cmd);
    while (*current_arg)
    {
        t_arg *arg = (t_arg *)(*current_arg)->content;
        if (arg->type == EXEC)
        {
            cmd.name = arg->content;
            cmd.path = find_executable_path(cmd.name, var->l_env);
            *current_arg = (*current_arg)->next;
            break;
        }
        *current_arg = (*current_arg)->next;
    }

    return cmd;
}

void parse_and_execute(t_var *var)
{
    t_list	*current_arg = var->l_arg;
    t_cmd	cmd;
    int		should_fork;

    while (current_arg)
    {
        should_fork = 0;
        cmd = get_next_command(&current_arg, var);

        if (cmd.name)
        {
            should_fork = handle_redirections(&cmd, &current_arg, var);
            if (should_fork)
            {
                fork_and_exec_command(&cmd, var);
            }
            else
            {
                exec_command(cmd.path, cmd.flags, cmd.arg, var);
            }
            free_cmd(&cmd);
        }
    }
}
