/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:09:03 by bgales            #+#    #+#             */
/*   Updated: 2023/02/20 14:36:33 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/ioctl.h>

void	signal_handler(int signo)
{
	// struct termios term_save;

	// tcgetattr(STDIN_FILENO, &term_save);
	// tcsetattr(STDIN_FILENO, TCSADRAIN, &term_save);
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
		rl_replace_line("", 0);
		rl_redisplay();
	}
		return;
}

void	get_signo(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = signal_handler;
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error: sigaction");
        exit(1);
    }signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTSTP, signal_handler);
}