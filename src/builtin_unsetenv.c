/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:24:08 by awindham          #+#    #+#             */
/*   Updated: 2019/03/07 14:13:22 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

char	**g_env;
int		g_env_len;

int		get_key(char *key)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(key);
	while (g_env[++i])
		if (ft_strncmp(g_env[i], key, len) == 0)
			return (i);
	return (-1);
}

void	env_del(int d)
{
	if (d < 0)
		return ;
	free(g_env[d]);
	while (d < g_env_len)
	{
		g_env[d] = g_env[d + 1];
		d++;
	}
	g_env[d] = 0;
	g_env_len -= 1;
}

int		builtin_unsetenv(char **tokens)
{
	if (tokens[1] == 0)
		return (0);
	env_del(get_key(tokens[1]));
	if (g_path)
		free_tab(g_path);
	g_path = 0;
	set_home();
	set_path();
	return (0);
}
