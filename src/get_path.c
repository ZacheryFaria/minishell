/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:59:17 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/04 14:21:20 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

extern char **environ;

char		**get_path(void)
{
	int i;

	i = 0;
	while (environ[i])
	{
		if (ft_strstr(environ[i], "PATH") && !ft_strstr(environ[i], "MANPATH"))
			return (ft_strsplit(environ[i], ':'));
		i++;
	}
	return (0);
}
