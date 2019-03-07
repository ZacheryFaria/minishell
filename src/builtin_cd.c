/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:49:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/06 19:01:14 by zfaria           ###   ########.fr       */
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
	char	*cwd;
	int		res;

	cwd = ft_strnew(4096);
	getcwd(cwd, 4096);
	if (path && path[0] == '~')
	{
		newpath = ft_strjoin(g_home, path + 1);
		free(path);
		path = newpath;
		path = ft_strcat(cwd, path);
	}
	else if (!path)
		path = g_home;
	if ((res = access(path, F_OK)) == -1)
		ft_printf("%s: %s: %s\n", "cd", path, "no such directory");
	else if ((res = access(path, R_OK)) == -1)
		ft_printf("%s: %s: %s\n", "cd", path, "permission denied");
	else
		status = chdir(path);
}

int		builtin_cd(char **token)
{
	cd(token[1]);
	return (0);
}
