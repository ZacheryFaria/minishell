/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:25:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/07 12:35:35 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <minishell.h>

extern char **g_env;

int			builtin_exit(char **tokens)
{
	int		status;
	char	*arr[1];

	(void)tokens;
	arr[0] = ft_strdup("fortune");
	status = check_path(arr);
	ft_putendl("goodbye");
	exit(1);
	return (0);
}
