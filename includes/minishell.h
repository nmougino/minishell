/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:02:17 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/30 16:38:30 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

# define DEFPROMPT "msh>"

typedef struct		s_env
{
	char			*name;
	char			*cont;
	struct s_env	*next;
}					t_env;

void				free_env(t_env *menv);
void				env_del_one(t_env *elem);
void				free_com(char **com);

t_env				*env_new(char *name, char *cont);
int					env_add(t_env **menv, char *name, char *cont);
int					env_rm(t_env **menv, char *tar);
void				env_disp(t_env *menv);
int					env_set(t_env *menv, char *tar, char *new_cont);

char				*env_get(t_env *menv, char *tar);

int					is_env(t_env *menv, char *tar);

t_env				*env_init(char **native);

char				*get_exe(char *pathes, char *exe);

void				exe_fork(t_env *menv, char **com);

void				exe_bi(t_env **menv, char **com);

void				bi_cd(t_env *menv, char **com);

void				bi_echo(t_env *env, char **com);

void				bi_setenv(t_env **menv, char **com);

size_t				get_env_len(t_env *env);
char				**env_conv(t_env *menv);

void				wheel(t_env **menv);

#endif
