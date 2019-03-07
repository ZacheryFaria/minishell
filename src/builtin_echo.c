/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:57:43 by awindham          #+#    #+#             */
/*   Updated: 2019/03/06 18:03:12 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		builtin_echo(char **tokens)
{
	while (*tokens++)
		ft_printf("%s ", *tokens);
	ft_printf("\n");
	return (0);
}
