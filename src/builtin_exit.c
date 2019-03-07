/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:25:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/06 16:33:39 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <minishell.h>

extern char **g_env;

int			builtin_exit(char **tokens)
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
