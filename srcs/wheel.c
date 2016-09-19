/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:24:56 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/19 02:13:50 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(t_env *menv)
{
	t_env	*tar;

	tar = env_get(menv, "PROMPT");
	if (tar)
		ft_putstr(tar->cont);
}

static int	init_wheel(char **line, t_env *menv)
{
	if (*line)
		free(*line);
	print_prompt(menv);
	get_next_line(0, line);
	return (1);
}

void	wheel(t_env *menv)
{
	char	*line;
	int		live;

	live = 1;
	line = NULL;
	while(live && init_wheel(&line, menv) && ft_strcmp("exit", line))
		if (line && line[0])
			live = exe_exe(menv, line);
	free(line);
}
