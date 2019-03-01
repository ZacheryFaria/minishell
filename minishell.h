/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:08:30 by awindham          #+#    #+#             */
/*   Updated: 2019/03/01 13:35:07 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

char	*read_line();
char	**tokenize(char *buf);
char	*eval(char **tokens);
void	cleanup(char *buf, char **tokens);
void	error(char *error);
void	prompt();

#endif
