/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:02:17 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 00:06:34 by nmougino         ###   ########.fr       */
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

char				*env_extract(char **env, char *tar);
void				env_add(t_env **menv, char *name, char *cont);
t_env				*env_init(char **env);

void				bi_env(t_env *menv);

void				free_env(t_env *menv);

#endif
