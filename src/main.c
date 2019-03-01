/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:08:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/01 14:15:28 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>

void repl()
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
		cleanup(buf, tokens);
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

int	main()
{
	signal(SIGINT, test);
	repl();
	return (0);
}
