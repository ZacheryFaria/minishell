/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:51:05 by awindham          #+#    #+#             */
/*   Updated: 2019/03/06 17:52:38 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char **g_env;

void	print_env(void)
{
	int i;

	i = 0;
	while (g_env[i])
		ft_printf("%s\n", g_env[i++]);
}

int		builtin_env(char **tokens)
{
	print_env();
	(void)tokens;
	return (0);
}
