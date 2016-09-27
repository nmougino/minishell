/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_bi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 04:09:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/27 04:27:03 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exe_bi(t_env **menv, char **com)
{
	if (!ft_strcmp(com[0], "env"))
		env_disp(*menv);
	if (!ft_strcmp(com[0], "setenv"))
	{
		if (com[1] && com[2])
			env_add(menv, com[1], com[2]);
		else
			ft_putendl("minishell: setenv: usage: setenv [NAME] [VALUE]");
	}
	if (!ft_strcmp(com[0], "unsetenv"))
	{
		if (com[1])
			env_rm(menv, com[1]);
		else
			ft_putendl("minishell: unsetenv: usage: unsetenv [NAME]");
	}

}
