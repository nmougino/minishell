/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 04:09:42 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/19 02:01:57 by nmougino         ###   ########.fr       */
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
	ans = (char *)malloc(sizeof(char) * (ft_strlen(line) + len + 1));
	bzero(ans, (ft_strlen(line) + len + 1));
	ft_strncpy(ans, path, len);
	ans[len] = '/';
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
		while (*path && lstat(ans, &buf))
		{
			free(ans);
			ans = NULL;
			while (*path && *path != ':')
				++path;
			if (*path)
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
	execve(path, tab, NULL);
}

static char	*get_com(char *line)
{
	char	*ans;
	size_t	len;

	len = 0;
	while (line[len] && line[len] != ' ')
		++len;
	ans = (char *)malloc(sizeof(char) * (len + 1));
	ft_strncpy(ans, line, len);
	ans[len] = '\0';
	return (ans);
}

int			exe_exe(t_env *menv, char *line)
{
	pid_t	pid;
	char	*path;
	char	**tab;
	int		ans;
	char	*com;

	ans = 1;
	tab = NULL;
	com = get_com(line);
	if ((path = get_path(env_get(menv, "PATH"), com)))
	{
		pid = fork();
		if (!pid)
		{
			tab = ft_strsplit(line, ' ');
			exe_launcher(menv, path, tab);
			ans = 0;
			free_av(tab);
		}
		else
			wait(NULL);
	}
	else
		ft_printf("minishell: command not found: %s\n", com);
	free(com);
	return (ans);
}
