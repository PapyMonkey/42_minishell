/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< Updated upstream:src/builtins/b_exit.c
/*   Created: 2022/12/06 05:55:53 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/06 05:58:03 by aguiri           ###   ########.fr       */
=======
/*   Created: 2022/12/04 11:09:36 by aguiri            #+#    #+#             */
/*   Updated: 2023/03/25 23:16:07 by aguiri           ###   ########.fr       */
>>>>>>> Stashed changes:src/builtins/builtin_utils.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream:src/builtins/b_exit.c
void	b_exit(t_var *var)
{
	free_var(var);
	exit (EXIT_SUCCESS);
=======
void	err_malloc_exit(void)
{
	ft_printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void	err_put_exit(void)
{
	ft_printf("Error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	err_put_exit_command_not_found(char *str)
{
	ft_printf("Error: command not found: %s\n", str);
	exit(EXIT_FAILURE);
>>>>>>> Stashed changes:src/builtins/builtin_utils.c
}
