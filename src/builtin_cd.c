/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:49:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/06 16:34:59 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdlib.h>
#include <minishell.h>

char	*g_home;

void	cd(char *path)
{
	int		status;
	char	*newpath;

	if (path && path[0] == '~')
	{
		newpath = ft_strjoin(g_home, path + 1);
		free(path);
		path = newpath;
	}
	else if (!path)
		path = g_home;
	status = chdir(path);
	if (status == -1)
		ft_printf("%s: %s: %s\n", "cd", path, "No such directory.");
}

int		builtin_cd(char **token)
{
	cd(token[1]);
	return (0);
}