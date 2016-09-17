/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 03:31:27 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 18:58:36 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_one(t_env *env)
{
	if (env->name)
		free(env->name);
	if (env->cont)
		free(env->cont);
	free(env);
}

void	free_env(t_env *menv)
{
	t_env	*tmp;

	while (menv)
	{
		tmp = menv->next;
		free_env_one(menv);
		menv = tmp;
	}
}
