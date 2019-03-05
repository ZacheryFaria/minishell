/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:51:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/05 13:05:00 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

char	**g_env;

void	print_env()
{
	int i;
	int len;

	len = array_len(g_env);
	i = 0;
	while (i < len)
	{
		ft_printf("%s\n", g_env[i]);
		i++;
	}
}

char	**realloc_env()
{
	char	**new;
	int		i;
	int		len;

	len = array_len(g_env);
	new = ft_memalloc(sizeof(char *) * len + 1);
	i = 0;
	while (g_env[i] && i < len)
	{
		new[i] = ft_strdup(g_env[i]);
		free(g_env[i]);
		i++;
	}
	new[i] = 0;
	free(g_env);
	return (new);
}

int		setenv_builtin(char **tokens)
{
	int		len;
	char	*str;

	if (!tokens[1])
	{
		print_env();
		return (0);
	}
	g_env = realloc_env();
	len = array_len(g_env);
	str = ft_strnew(ft_strlen(tokens[1]) + ft_strlen(tokens[2]) + 2);
	ft_strcat(str, tokens[1]);
	ft_strcat(str, "=");
	if (tokens[2])
		ft_strcat(str, tokens[2]);
	g_env[len] = str;
	g_env[len + 1] = 0;
	set_path();
	set_home();
	return (0);
}