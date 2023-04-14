/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:28:18 by aguiri            #+#    #+#             */
/*   Updated: 2023/04/14 01:38:47 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NOTE: Documentation
static char	*recover_val(
	t_list *l_env,
	char *key,
	t_var *var)
{
	char	*value;
	t_list	*elem;

	key++;
	elem = search_env_elem(var->l_env, key);
	if (elem)
		value = ft_strdup(get_env_value(elem));
	else
		value = ft_strdup("");
	return (value);
}

// NOTE: Documentation
static char	*replace_str_heredoc(
	char *orig_str,
	char *val_str,
	int index)
{
	char	*new_str;
	int		orig_len;
	int		val_len;

	orig_len = ft_strlen(orig_str);
	val_len = ft_strlen(val_str);
	new_str = malloc(orig_len - 1 + val_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, orig_str, index + 1);
	ft_strlcpy(new_str + index, val_str, val_len + 1);
	free(orig_str);
	free(val_str);
	return (new_str);
}

// NOTE: Documentation
static char	*make_str_from_tab(char **words)
{
	char	*result;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (words[i])
	{
		len += ft_strlen(words[i]) + 1;
		i++;
	}
	result = malloc(len);
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (words[i])
	{
		ft_strlcat(result, words[i], len);
		if (words[i + 1])
			ft_strlcat(result, " ", len);
		i++;
	}
	return (result);
}

// NOTE: Documentation
static char	*heredoc_expander(
	t_var *var,
	char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$'
			&& str[i + 1] != '$')
			str = replace_str_heredoc(str, recover_val(NULL, str + i, var), i);
		else
			i++;
	}
	return (str);
}

char	*heredoc_split_to_expander(
	t_var *var,
	char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	if (!words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$'))
		{
			words[i] = heredoc_expander(var, words[i]);
			if (!words[i])
				return (NULL);
		}
		i++;
	}
	return (make_str_from_tab(words));
}
