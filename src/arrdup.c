/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:36:00 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/04 16:41:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char **arrdup(char **arr)
{
	char	**res;
	int		i;
	int		len;

	i = 0;
	len = array_len(arr);
	res = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		res[i] = ft_strdup(arr[i]);
		i++;
	}
	return (res);
}
