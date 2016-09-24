/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:13:19 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/23 17:31:02 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_del_one(t_env *elem)
{
	free(elem->name);
	free(elem->cont);
	free(elem);
}

void	free_env(t_env *menv)
{
	t_env	*tmp;

	while (menv)
	{
		tmp = menv->next;
		env_del_one(menv);
		menv = tmp;
	}
}

void	free_com(char **com)
{
	int	i;

	i = 0;
	while (com[i])
		free(com[i++]);
	free(com);
}
