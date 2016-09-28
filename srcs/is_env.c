/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 04:50:35 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/27 04:50:36 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_env(t_env *menv, char *tar)
{
	while (menv)
	{
		if (!ft_strcmp(tar, menv->name))
			return (1);
		menv = menv->next;
	}
	return (0);
}
