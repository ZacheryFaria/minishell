/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:14:25 by awindham          #+#    #+#             */
/*   Updated: 2019/03/01 13:17:41 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	**tokenize(char *buf)
{
	char **done = malloc(99);
	
	done[0] = "hello";
	done[1] = "world";
	ft_putendl(buf);
	return (done);
}
