/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:02:17 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/23 17:31:16 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

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
void				env_add(t_env **menv, char *name, char *cont);
int					env_rm(t_env **menv, char *tar);
void				env_disp(t_env *menv);
int					env_set(t_env *menv, char *tar, char *new_cont);

t_env				*env_init(char **native);

void				wheel(t_env *menv);

#endif
