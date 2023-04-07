/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:09:03 by bgales            #+#    #+#             */
/*   Updated: 2023/04/07 17:07:09 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_status(int no)
{
	static struct termios	t;
		tcgetattr(0, &t);
		t.c_lflag &= ~ECHOCTL;
		tcsetattr(0, TCSANOW, &t);

}

void	show_ctrl()
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag |= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

/*
@brief Handle signals (SIGINT and SIGQUIT).

@param signo   The signal number.
*/
void	signal_handler(int signo)
{
	ctrl_status(1);
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
	// ctrl_status(0);
	return ;
}

void	signal_handler2(int signo)
{
	// struct termios	t;

	// tcgetattr(0, &t);
	// t.c_lflag |= ~ECHOCTL;
	// tcsetattr(0, TCSANOW, &t);
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		rl_redisplay();
	}
	return ;
}

void	get_signo(int no)
{
	if (!no)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
	}
	if (no)
	{
		signal(SIGINT, signal_handler2);
		signal(SIGQUIT, signal_handler2);
	}
}
