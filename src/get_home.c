/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:19:15 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/04 15:22:24 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

extern char **environ;

char		*get_home(void)
{
	int i;

	i = 0;
	while (environ[i])
	{
		if (ft_strstr(environ[i], "HOME"))
			return (environ[i] + 5);
		i++;
	}
	return (0);
}
