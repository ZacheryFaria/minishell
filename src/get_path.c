/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:59:17 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/04 17:06:08 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

extern char **g_env;

char		**get_path(void)
{
	int i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strstr(g_env[i], "PATH") && !ft_strstr(g_env[i], "MANPATH"))
			return (ft_strsplit(g_env[i], ':'));
		i++;
	}
	return (0);
}
