/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:02:17 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 20:28:39 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/wait.h>
# include "libft.h"

/*
**	venv contient les variables d'environement
**	on peut envisager d'ajouter une autre structure pour stocker l'historique
*/

typedef struct		s_env
{
	char			*name;
	char			*cont;
	struct s_env	*next;
}					t_env;

void				env_set(t_env *env, char *new_val);
t_env				*env_get(t_env *menv, char *tar);
void				env_add(t_env **menv, const char *name, char *cont);
int					env_rm(t_env **menv, char *tar);

t_env				*env_init(char **env);

void				bi_env(t_env *menv);

void				free_env_one(t_env *env);
void				free_env(t_env *menv);

#endif
