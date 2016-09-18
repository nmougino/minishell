/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 04:09:42 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/19 00:13:37 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cpy_path(char *path, char *line)
{
	char	*ans;
	size_t	len;

	len = 0;
	while (path[len] && path[len] != ':')
		++len;
	ans = (char *)malloc(sizeof(char) * (ft_strlen(line) + len));
	len = 0;
	while (path[len] && path[len] != ':')
	{
		ans[len] = path[len];
		++len;
	}
	ft_strcat(ans, line);
	return (ans);
}

static char	*get_path(t_env *menv, char *line)
{
	char		*ans;
	struct stat	buf;
	char		*path;

	ans = NULL;
	if (menv)
	{
		path = menv->cont;
		ans = cpy_path(path, line);
		while (path && lstat(ans, &buf))
		{
			free(ans);
			ans = NULL;
			while (*path && *path != ':')
				++path;
			if (path)
			{
				++path;
				ans = cpy_path(path, line);
			}
		}
	}
	return (ans);
}

static void	exe_launcher(t_env *menv, char *path, char **tab)
{
	(void)menv;
	ft_printf("commande: %s\n", path);
	(void)tab;
}

void		exe_exe(t_env *menv, char *line)
{
	pid_t	pid;
	char	*path;
	char	**tab;

	tab = ft_strsplit(line, ' ');
	ft_printf("prout line : %s\n", line);
	ft_printf("rendu env_get = %p\n", menv);
	if ((path = get_path(env_get(menv, "PATH"), tab[0])))
	{
		pid = fork();
		if (!pid)
			exe_launcher(menv, path, tab + 1);
		else
			wait(NULL);
	}
	else
		ft_printf("minishell: %s: commande introuvable\n", tab[0]);
	free_av(tab);
}
