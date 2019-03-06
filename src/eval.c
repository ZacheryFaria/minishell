/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:12:47 by awindham          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2019/03/06 11:44:48 by zfaria           ###   ########.fr       */
=======
/*   Updated: 2019/03/06 12:12:36 by awindham         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <minishell.h>
#include <libft.h>

extern char **g_env;
extern char **g_path;

t_builtin g_dispatch[] = {
	{ "cd", &cd_builtin },
	{ "exit", &exit_builtin },
	{ "setenv", &setenv_builtin }
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
	if (!check_builtin(tokens) && check_literal(tokens) == 1280
		&& check_path(tokens) == 1280)
	{
		ft_printf("%s: %s\n", tokens[0], "Command not found.");
	}
	return (0);
}
