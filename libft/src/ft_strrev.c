/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 09:49:37 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 14:54:49 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(unsigned char *str)
{
	int				i;
	int				j;
	unsigned char	a;
	unsigned char	len;

	len = ft_strlen((const char *)str);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i++;
		j--;
	}
}
