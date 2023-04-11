/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerbaud <mgerbaud@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:45:15 by mgerbaud          #+#    #+#             */
/*   Updated: 2022/12/06 04:12:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_pwd(t_var *const var)
{
	t_list	*flag;

	flag = check_arg_flag(var->current_arg);
	if (flag)
		return (err_d("pwd", get_arg_content(flag), "invalid option", 2));
	printf("%s\n", g_process.pwd);
	g_process.return_code = 0;
}
