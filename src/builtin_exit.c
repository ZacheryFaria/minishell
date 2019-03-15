/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:25:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/15 10:14:55 by awindham         ###   ########.fr       */
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
	status = check_path(arr, -1);
	ft_putendl("goodbye");
	exit(1);
	return (0);
}
