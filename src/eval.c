/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:22:31 by awindham          #+#    #+#             */
/*   Updated: 2019/03/07 14:42:12 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <minishell.h>

extern char **g_env;
extern char **g_path;

t_builtin g_dispatch[] = {
	{ "cd", &builtin_cd },
	{ "exit", &builtin_exit },
	{ "setenv", &builtin_setenv },
	{ "unsetenv", &builtin_unsetenv },
	{ "env", &builtin_env },
	{ "echo", &builtin_echo }
};

int		check_builtin(char **str)
{
	int i;

	i = 0;
	while (g_dispatch[i].cmd)
	{
		if (ft_strcmp(str[0], g_dispatch[i].cmd) == 0)
		{
			g_dispatch[i].cmdf(str);
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_literal(char **tokens)
{
	int		status;
	int		pid;

	pid = fork();
	signal(SIGINT, proc_signal_handle);
	if (pid == 0)
	{
		execve(tokens[0], tokens, g_env);
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
	int		pid;

	pid = fork();
	signal(SIGINT, proc_signal_handle);
	if (pid == 0)
	{
		i = -1;
		while (g_path[++i])
		{
			func = ft_strnew(ft_strlen(g_path[i]) + ft_strlen(tokens[0]) + 2);
			func = ft_strvcat(func, g_path[i], "/", tokens[0], 0);
			if (access(func, F_OK) == 0 && access(func, X_OK) == -1)
			{
				ft_printf("%s: %s\n", tokens[0], "permission denied");
				exit(6);
			}
			execve(func, tokens, g_env);
			free(func);
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
	int status_builtin;
	int status_literal;
	int status_path;

	if ((status_builtin = check_builtin(tokens)) == 0)
		if ((status_literal = check_literal(tokens)) == 1280)
		{
			if (access(tokens[0], F_OK) == 0 && access(tokens[0], X_OK) == -1)
				ft_printf("%s: %s\n", tokens[0], "permission denied");
			else if (((status_path = check_path(tokens)) == 1280
				|| status_path == 11) && status_path>>8 != 6)
				ft_printf("%s: %s\n", tokens[0], "command not found");
		}
	return (0);
}
