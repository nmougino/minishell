/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 20:42:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/28 20:44:49 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get(t_env *menv, char *tar)
{
	while (menv && ft_strcmp(menv->name, tar))
		menv = menv->next;
	return (menv ? menv->cont : NULL);
}
