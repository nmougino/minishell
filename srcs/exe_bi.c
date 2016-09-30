/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_bi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 04:09:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/01 01:30:07 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	bi_help(t_env *menv)
{
	int		fd;
	char	*fpath;
	size_t	len;

	if (!is_env(menv, "SHELL"))
		ft_dprintf(2, "minishell: help: no README.md in minishell directory");
	else
	{
		len = ft_strlen(env_get(menv, "SHELL")) + 10;
		fpath = ft_strnew(len);
		ft_strcpy(fpath, env_get(menv, "SHELL"));
		ft_strcat(fpath, "/README.md");
		if ((fd = open(fpath, O_RDONLY)) >= 0)
		{
			free(fpath);
			while (get_next_line(fd, &fpath))
			{
				ft_putendl(fpath);
				free(fpath);
			}
		}
		else
			ft_dprintf(2, "minishell: help: can't open %s\n", fpath);
	}
}

/*
** env -i simple,
** le posix gere l'ajout de variable par dessus un env vierge
*/

static void	bi_env(t_env *menv, char **com)
{
	if (com[1] && ft_strequ("-i", com[1]))
	{
		if (com[2])
			exe_fork(NULL, com + 2);
	}
	else
		env_disp(menv);
}

void		exe_bi(t_env **menv, char **com)
{
	if (!ft_strcmp(com[0], "env"))
		bi_env(*menv, com);
	else if (!ft_strcmp(com[0], "setenv"))
		bi_setenv(menv, com);
	else if (!ft_strcmp(com[0], "unsetenv"))
	{
		if (com[1])
			env_rm(menv, com[1]);
		else
			ft_putendl("minishell: unsetenv: usage: unsetenv [NAME]");
	}
	else if (!ft_strcmp(com[0], "echo"))
		bi_echo(*menv, com);
	else if (!ft_strcmp(com[0], "cd"))
		bi_cd(*menv, com);
	else if (!ft_strcmp(com[0], "help"))
		bi_help(*menv);
}
