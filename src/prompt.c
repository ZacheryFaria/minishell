/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:22:30 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/06 13:59:49 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/stat.h>
#include <unistd.h>

char	*g_home;

void	prompt(void)
{
	char		*buf;

	buf = ft_strnew(4096);
	getcwd(buf, 4096);
	if (ft_strncmp(buf, g_home, ft_strlen(g_home)) == 0)
		buf[ft_strlen(g_home) - 1] = '~';
	if (buf[ft_strlen(g_home) - 1] == '~')
		ft_printf("%s %c ", buf + ft_strlen(g_home) - 1, '$');
	else
		ft_printf("%s %c ", buf, '$');
		
	ft_strdel(&buf);
}
