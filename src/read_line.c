/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:13:30 by awindham          #+#    #+#             */
/*   Updated: 2019/03/04 14:21:55 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

char	*read_line(void)
{
	char *done;

	prompt();
	if (get_next_line(0, &done, 512) == 0)
		exit(-1);
	return (done);
}
