/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:14:25 by awindham          #+#    #+#             */
/*   Updated: 2019/03/07 12:49:00 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <minishell.h>

char	*g_home;

char	**tokenize(char *buf)
{
	char	**done;
	char	*bak;
	int		i;

	done = ft_strsplit(buf, ' ');
	i = 0;
	while (done[i])
	{
		if (done[i][0] == '~')
		{
			bak = done[i];
			done[i] = ft_strjoin(g_home, bak + 1);
			free(bak);
		}
		bak = ft_strtrim(done[i]);
		free(done[i]);
		done[i] = bak;
		if (done[i][0] == 0)
			ft_strdel(&done[i]);
		else
			i++;
	}
	return (done);
}
