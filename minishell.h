/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:21:44 by awindham          #+#    #+#             */
/*   Updated: 2019/03/11 14:56:14 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_builtin
{
	char		*cmd;
	int			(*cmdf)(char **);
}				t_builtin;

char			**g_path;
char			*g_home;

char			*read_line(void);
char			**tokenize(char *buf);
char			*eval(char **tokens);
void			cleanup(char *buf, char **tokens, char *err);
void			error(char *error);
void			prompt(void);
void			set_path(void);
void			set_home(void);
void			cd(char *path);
void			signal_handle(int sig);
void			proc_signal_handle(int sig);
void			print_env(void);
void			expand_var(char **tokens);
int				check_path(char **tokens);
int				get_key(char *key);

int				builtin_cd(char **token);
int				builtin_exit(char **tokens);
int				builtin_setenv(char **tokens);
int				builtin_unsetenv(char **tokens);
int				builtin_env(char **tokens);
int				builtin_echo(char **tokens);

#endif
