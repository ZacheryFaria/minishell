/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:08:30 by awindham          #+#    #+#             */
/*   Updated: 2019/03/04 10:51:51 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

char	**g_path;

char	*read_line();
char	**tokenize(char *buf);
char	*eval(char **tokens);
void	cleanup(char *buf, char **tokens, char *err);
void	error(char *error);
void	prompt();
char	**get_path();

#endif
