/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:12:47 by awindham          #+#    #+#             */
/*   Updated: 2019/03/04 14:11:46 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <minishell.h>
#include <libft.h>

extern char **environ;
extern char **g_path;

t_builtin tab[] = {
	{ "cd", &cd_builtin },
	{ "exit", &exit_builtin }
};


int		check_builtin(char **str)
{
	int i;

	i = 0;
	while (tab[i].cmd)
	{
		if (ft_strcmp(str[0], tab[i].cmd) == 0)
		{
			tab[i].cmdf(str);
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_literal(char **tokens)
{
	int		status;

	if (fork() == 0)
	{
		execve(tokens[0] , tokens, environ);
		exit(5);
		return (0);
	}
	else
	{
		wait(&status);
		return (status);
	}
}

int		check_path(char **tokens)
{
	char	*func;
	int		status;
	int		i;

	if (fork() == 0)
	{
		i = 0;
		while (g_path[i])
		{
			func = ft_strnew(ft_strlen(g_path[i]) + ft_strlen(tokens[0]) + 2);
			func = ft_strcat(func, g_path[i]);
			func = ft_strcat(func, "/");
			func = ft_strcat(func, tokens[0]);
			execve(func, tokens, environ);
			i++;
		}
		exit(5);
		return (0);
	}
	else
	{
		wait(&status);
		return (status);
	}
}

char	*eval(char **tokens)
{
	if (!check_builtin(tokens) && check_literal(tokens) == 1280
		&&check_path(tokens) == 1280)
	{
		ft_printf("%s: %s\n", tokens[0], "Command not found.");
	}
	return (0);
}
