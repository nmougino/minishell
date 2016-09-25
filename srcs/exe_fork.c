/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:45:42 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/25 18:15:22 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** renvoie le pid afin que wheel determine
** s'il s'agit du processus pere ou fils
** renvoie 1 en cas d'erreur apres avoir affiche l'erreur
*/

int		exe_fork(t_env *menv, char **com)
{
	t_env	*tmp;
	char	*path;
	char	*exe;

	tmp = menv;
	path = NULL;
	while (tmp && ft_strcmp(tmp->name, "PATH"))
		tmp = tmp->next;
	if (tmp)
		path = tmp->cont;
	exe = get_exe(path, com[0]);
	if (exe)
	{
		ft_printf("command path = %s\n", exe);
		free(exe);
	}
	else
		ft_dprintf(2, "minishell: %s: command not found\n", com[0]);
	return (1);
}
