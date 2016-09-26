/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:45:42 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/26 22:14:24 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** renvoie le pid afin que wheel determine
** s'il s'agit du processus pere ou fils
** renvoie 1 en cas d'erreur apres avoir affiche l'erreur
*/

static void	do_fork(char *exe, char **com, t_env *menv)
{
	pid_t	pid;
	char	**env;

	pid = fork();
	env = env_conv(menv);
	if (!pid)
		execve(exe, com, env);
	else
	{
		waitpid(pid, NULL, 0);
		free_com(env);
		free(exe);
	}
}

void		exe_fork(t_env *menv, char **com)
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
		do_fork(exe, com, menv);
	else
		ft_dprintf(2, "minishell: command not found: %s\n", com[0]);
}
