/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:08:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/04 15:20:39 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>

char	**g_path = 0;
char	*g_home = 0;

void repl(void)
{
	char *buf;
	char **tokens;
	char *err;

	while (1)
	{
		buf = read_line();
		tokens = tokenize(buf);
		err = eval(tokens);
		error(err);
		cleanup(buf, tokens, err);
	}
}

void test(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		prompt();
	}
}

int		main(void)
{
	g_path = get_path();
	g_home = get_home();
	signal(SIGINT, test);
	repl();
	return (0);
}
