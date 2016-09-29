/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:23:20 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 18:27:51 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_setenv(t_env **menv, char **com)
{
	if (com[1] && com[2])
	{
		if (!is_env(*menv, com[1]))
			env_add(menv, com[1], com[2]);
		else
			env_set(*menv, com[1], com[2]);
	}
	else
		ft_putendl("minishell: setenv: usage: setenv [NAME] [VALUE]");
}
