/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:12:47 by awindham          #+#    #+#             */
/*   Updated: 2019/03/04 10:51:01 by zfaria           ###   ########.fr       */
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
	int	i;

	
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
		return (ft_strjoin("Unknown command: ", tokens[0]));
	}
	else
		wait(&status);
	return (0);
}
