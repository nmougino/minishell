/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 03:31:27 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/19 01:10:53 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	free_env_one(t_env *env)
{
	if (!ft_strcmp(env->name, "SHLVL"))
		free(env->cont);
	if (env->name)
		free(env->name);
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
