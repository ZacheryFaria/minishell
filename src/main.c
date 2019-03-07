/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:08:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/07 13:02:51 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>

char	**g_path = 0;
char	*g_home = 0;
char	**g_env;
int		g_env_len;

void	run_commands(char **commands)
{
	char	**tokens;
	char	*err;
	int		i;

	i = 0;
	while (commands[i])
	{
		tokens = tokenize(commands[i]);
		expand_var(tokens);
		if (tokens[0])
		{
			err = eval(tokens);
			error(err);
			free_tab(tokens);
			ft_strdel(&err);
		}
		else
			free(tokens);
		i++;
	}
	free_tab(commands);
}

void	repl(void)
{
	char *buf;
	char **commands;

	while (1)
	{
		buf = read_line();
		if (*buf == 0)
		{
			ft_strdel(&buf);
			continue ;
		}
		commands = ft_strsplit(buf, ';');
		run_commands(commands);
		ft_strdel(&buf);
	}
}

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_env = arrdup(env);
	g_env_len = array_len(env);
	signal(SIGINT, signal_handle);
	set_path();
	set_home();
	repl();
	return (0);
}
