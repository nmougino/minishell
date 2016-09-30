/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:05:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/30 16:37:31 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	bi_cd_err(char *tar)
{
	struct stat	buf;

	if (lstat(tar, &buf))
		ft_dprintf(2, "cd: no such file or directory: %s\n", tar);
	else if (access(tar, F_OK))
		ft_dprintf(2, "cd: file is not accessible: %s\n", tar);
	else if (access(tar, X_OK))
		ft_dprintf(2, "cd: permission denied: %s\n", tar);
	else
		ft_dprintf(2, "cd: unknow error: %s\n", tar);
}

static void	bi_cd_addpwd(t_env *menv)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	env_set(menv, "OLDPWD", env_get(menv, "PWD"));
	env_set(menv, "PWD", tmp);
	free(tmp);
}

static void	bi_chdir(t_env *menv, char *com)
{
	if (chdir(com))
		bi_cd_err(com);
	else
	{
		if (is_env(menv, "PWD"))
		{
			if (!is_env(menv, "OLDPWD"))
				env_set(menv, "PWD", com);
			else
				bi_cd_addpwd(menv);
		}
	}
}

void		bi_cd(t_env *menv, char **com)
{
	if (!com[1])
	{
		if (is_env(menv, "HOME"))
			bi_chdir(menv, env_get(menv, "HOME"));
		else
			ft_dprintf(2, "cd: HOME not set\n");
	}
	else
	{
		if (ft_strcmp("-", com[1]))
			bi_chdir(menv, com[1]);
		else
			bi_chdir(menv, env_get(menv, "OLDPWD"));
	}
}
