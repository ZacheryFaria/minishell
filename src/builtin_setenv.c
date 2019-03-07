/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:58:15 by awindham          #+#    #+#             */
/*   Updated: 2019/03/06 16:13:36 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <minishell.h>

char	**g_env;
int		g_env_len;

void	print_env()
{
	int i;

	i = 0;
	while (g_env[i])
		ft_printf("%s\n", g_env[i++]);
}

char	**arrayplusplus(char **a)
{
	char	**done;
	int		i;

	done = malloc((g_env_len + 2) * sizeof(char *));
	i = 0;
	while(a[i])
	{
		done[i] = ft_strdup(a[i]);
		free(a[i]);
		i++;
	}
	done[i] = 0;
	done[i + 1] = 0;
	g_env_len += 1;
	free(g_env);
	return (done);
}

void	env_append(char **tokens)
{
	char *str;

	g_env = arrayplusplus(g_env);
	str = ft_strnew(ft_strlen(tokens[1]) + ft_strlen(tokens[2]) + 1);
	str = ft_strvcat(str, tokens[1], "=", tokens[2], 0);
	g_env[g_env_len - 1] = str;
}

int		builtin_setenv(char **tokens)
{
	if (tokens[1] == 0)
		print_env();
	else
		env_append(tokens);
	free_tab(g_path);
	set_home();
	set_path();
	return (1);
}
