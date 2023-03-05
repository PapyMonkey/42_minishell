// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   lexer2.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/27 16:40:51 by bgales            #+#    #+#             */
// /*   Updated: 2023/03/02 18:25:24 by bgales           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"
// int	is_builtin(char *split)
// {
// 	return (0);
// }

// int is_quote(char c)
// {
// 	if (c == '\'')
// 		return (QUOTE);
// 	if (c == '\"')
// 		return (D_QUOTE);
// 	return (0);
// }

// // void	ft_lstiter(t_list *lst, void (*f)(void *))

// void print_list(t_list *list)
// {
// 	t_arg	*arg;
// 	arg = list->content;
// 	while (arg != NULL)
// 	{
// 		printf("%s\n", arg->content);
// 		list = list->next;
// 		arg = (t_arg *)list->content;
// 	}
// }
// t_list	*struct_init(char **split)
// {
// 	int		i = -1;
// 	int		c;
// 	int		quote_open = 2;

// 	t_list	*ret;
// 	t_arg	*arg;

// 	ret = NULL;
// 	while (split[++i])
// 	{
// 		c = -1;
// 		while(split[i][++c])
// 		{
// 			if (is_quote(split[i][c]))
// 			{
// 				arg = malloc(sizeof(t_arg));
// 				arg->content = ft_substr(&split[i][c], 0, 1);
// 				arg->type = is_quote(split[i][c]);
// 				ft_lstadd_back(&ret, ft_lstnew(arg));
// 			}
// 			if (enum_finder(&split[i][c]))
// 			{
// 				arg = malloc(sizeof(t_arg));
// 				arg->type = enum_finder(&split[i][c]);
// 				printf("%d\n", enum_finder(&split[i][c]));
// 				if (!enum_finder(&split[i][c]) % 2)
// 					arg->content = ft_substr(&split[i][c], 0, 1);
// 				else
// 					arg->content = ft_substr(&split[i][c++], 0, 2);
// 				ft_lstadd_back(&ret, ft_lstnew(arg));
// 			}
// 		}
// 	}
// 	ft_lstiter(ret, *print_arg_elem);
// 	return (ret);
// }