/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:19:15 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/05 11:59:14 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**g_env;
char		*g_home;

void	set_home(void)
{
	int i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strstr(g_env[i], "HOME"))
		{
			g_home = g_env[i] + 5;
			return ;
		}
		i++;
	}
}
