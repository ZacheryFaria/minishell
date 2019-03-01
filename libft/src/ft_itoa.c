/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:25:56 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/22 15:05:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	unsigned int	num;

	if (n == 0)
		return (ft_strdup("0"));
	res = ft_strnew(13);		
	if (res)
	{
		i = 0;
		if (n < 0)
			num = n * -1;
		else
			num = n;
		while (num > 0)
		{
			res[i++] = num % 10 + '0';
			num /= 10;
		}
		if (n < 0)
			res[i++] = '-';
		res[i] = 0;
		ft_strrev((unsigned char *)res);
		return (res);
	}
	return (NULL);
}
