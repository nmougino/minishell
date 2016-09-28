/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_bi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 04:09:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/28 19:33:13 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exe_bi(t_env **menv, char **com)
{
	if (!ft_strcmp(com[0], "env"))
		env_disp(*menv);
	else if (!ft_strcmp(com[0], "setenv"))
	{
		if (com[1] && com[2])
			env_add(menv, com[1], com[2]);
		else
			ft_putendl("minishell: setenv: usage: setenv [NAME] [VALUE]");
	}
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
}
