/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:49:11 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/04 13:24:07 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	cd(char *path)
{
	int status;
	
	status = chdir(path);
	if (status == -1)
		ft_printf("%s: %s: %s\n", "cd", path, "No such directory.");
}

int		cd_builtin(char **token)
{
	cd(token[1]);
	return (0);
}
