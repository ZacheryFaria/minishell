/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:59:17 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/07 12:30:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**g_env;
char	**g_path;

void	set_path(void)
{
	int i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strstr(g_env[i], "PATH") && !ft_strstr(g_env[i], "MANPATH"))
		{
			g_path = ft_strsplit(g_env[i] + 5, ':');
			return ;
		}
		i++;
	}
}
