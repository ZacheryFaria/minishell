/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:25:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/05 10:41:18 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <minishell.h>

extern char **g_env;

int			exit_builtin(char **tokens)
{
	int status;

	if (fork() == 0)
	{
		execve("/nfs/2018/z/zfaria/.brew/bin/fortune", tokens, g_env);
		exit(0);
	}
	else
	{
		wait(&status);
		ft_putendl("goodbye");
		exit(1337);
	}
	return (0);
}
