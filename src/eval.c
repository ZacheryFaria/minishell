/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:22:31 by awindham          #+#    #+#             */
/*   Updated: 2019/03/06 18:13:00 by zfaria           ###   ########.fr       */
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
		i = 0;
		while (g_path[i])
		{
			func = ft_strnew(ft_strlen(g_path[i]) + ft_strlen(tokens[0]) + 2);
			func = ft_strvcat(func, g_path[i], "/", tokens[0], 0);
			execve(func, tokens, g_env);
			free(func);
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
	int status_builtin;
	int status_literal;
	int status_path;

	status_builtin = check_builtin(tokens);
	status_literal = check_literal(tokens);
	status_path = check_path(tokens);
	if (!status_builtin && status_literal == 1280 && (status_path == 11 ||
		status_path == 1280))
	{
		ft_printf("%s: %s\n", tokens[0], "Command not found.");
	}
	return (0);
}
