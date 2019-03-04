/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:12:47 by awindham          #+#    #+#             */
/*   Updated: 2019/03/04 10:30:30 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <minishell.h>

extern char **environ;
extern char **g_path;

char	*eval(char **tokens)
{
	char *func;
	int	status;

	for (int i = 0; i < 2; i++)
	{
		ft_printf("%s\n", tokens[i]);
	}

	func = ft_strnew(ft_strlen(g_path[3]) + ft_strlen(tokens[0]) + 2);
	func = ft_strcat(func, g_path[3]);
	func = ft_strcat(func, "/");
	func = ft_strcat(func, tokens[0]);
	
	if (fork() == 0)
		execve(func, tokens, environ);
	else
		wait(&status);
	return (0);
}
