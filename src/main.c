/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:08:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/05 10:40:47 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>

char	**g_path = 0;
char	*g_home = 0;
char	**g_env;

void	repl(void)
{
	char *buf;
	char **tokens;
	char *err;

	while (1)
	{
		buf = read_line();
		if (*buf == 0)
		{
			ft_strdel(&buf);
			continue ;
		}
		tokens = tokenize(buf);
		err = eval(tokens);
		error(err);
		cleanup(buf, tokens, err);
	}
}

void	test(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		prompt();
	}
}

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_env = arrdup(env);
	g_path = get_path();
	g_home = get_home();
	signal(SIGINT, test);
	repl();
	return (0);
}
