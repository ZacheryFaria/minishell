/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:19:17 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/05 13:25:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <minishell.h>
#include <libft.h>

void	proc_signal_handle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, signal_handle);
	}
}

void	signal_handle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		prompt();
		signal(SIGINT, signal_handle);
	}
}
