/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:08:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/06 14:13:14 by awindham         ###   ########.fr       */
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

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_env = env;
	signal(SIGINT, signal_handle);
	set_path();
	set_home();
	repl();
	return (0);
}
