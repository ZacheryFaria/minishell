/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:14:25 by awindham          #+#    #+#             */
/*   Updated: 2019/03/04 16:18:29 by zfaria           ###   ########.fr       */
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
		i++;
	}
	return (done);
}
