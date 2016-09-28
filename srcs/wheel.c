/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:24:56 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/27 04:27:28 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**com_init(t_env *env)
{
	char	*line;
	char	**ans;

	line = NULL;
	while (env && ft_strcmp(env->name, "PROMPT"))
		env = env->next;
	if (env)
	{
		ft_putstr(env->cont);
		write(1, " ", 1);
	}
	get_next_line(0, &line);
	if (*line)
		ans = ft_strsplit(line, ' ');
	else
	{
		ans = (char **)malloc(sizeof(char *) * 2);
		ans[0] = ft_strnew(0);
		ans[1] = NULL;
	}
	free(line);
	return (ans);
}

static int	is_bi(char **com)
{
	const char	*tab[6] = {"echo", "cd", "setenv", "unsetenv", "env", NULL};
	int			i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], com[0]))
			return (1);
		++i;
	}
	return (0);
}

void		wheel(t_env *menv)
{
	int		live;
	char	**com;

	live = 1;
	while (live)
	{
		com = com_init(menv);
		if (com && *com && **com)
		{
			if (!ft_strcmp(com[0], "exit"))
				live = 0;
			else if (is_bi(com))
				exe_bi(&menv, com);
			else
				exe_fork(menv, com);
		}
		free_com(com);
	}
	ft_printf("exiting minishell...\n");
}
