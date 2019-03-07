/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:26:18 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/06 18:24:51 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

char	**g_env;

char	*get_env(char *key)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(key);
	while (g_env[++i])
		if (ft_strncmp(g_env[i], key, len) == 0)
			return (g_env[i] + len + 1);
	return (0);
}

char	*expand_var_str(char *token)
{
	int		i;
	char	*str;

	i = -1;
	while (token[++i])
	{
		if (token[i] == '$')
		{
			if (get_env(token + i + 1) == 0)
				return (0);
			str = ft_strnew(ft_strlen(get_env(token + i + 1)) + i);
			str = ft_strncat(str, token, i);
			str = ft_strcat(str, get_env(token + i + 1));
			return (str);
		}
	}
	return (ft_strdup(token));
}

void	expand_var(char **tokens)
{
	int		i;
	char	*new;

	i = 0;
	while (tokens[i] && tokens[i][0])
	{
		new = expand_var_str(tokens[i]);
		free(tokens[i]);
		tokens[i] = new;
		i++;
	}
}
