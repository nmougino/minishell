/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:55:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/22 14:24:18 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_new(char *name, char *cont)
{
	t_env	*ans;

	ans = (t_env *)malloc(sizeof(t_env));
	ans->next = NULL;
	ans->name = ft_strdup(name);
	ans->cont = ft_strdup(cont);
	return (ans);
}

int		env_set(t_env *menv, char *tar, char *new_cont)
{
	while (menv && ft_strcmp(menv->name, tar))
		menv = menv->next;
	if (!menv)
		return (0);
	free(menv->cont);
	menv->cont = ft_strdup(new_cont);
	return (1);
}

void	env_add(t_env **menv, char *name, char *cont)
{
	t_env	*elem;
	t_env	*tmp;

	elem = env_new(name, cont);
	if (!*menv)
		*menv = elem;
	else
	{
		tmp = *menv;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

int		env_rm(t_env **menv, char *tar)
{
	t_env	*prev;
	t_env	*cur;

	if (!menv || !(*menv))
		return (0);
	if (!ft_strcmp((*menv)->name, tar))
	{
		cur = *menv;
		(*menv) = (*menv)->next;
		env_del_one(cur);
		return (1);
	}
	prev = *menv;
	cur = (*menv)->next;
	while (cur && ft_strcmp(cur->name, tar))
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (0);
	prev->next = cur->next;
	env_del_one(cur);
	return (1);
}

void	env_disp(t_env *menv)
{
	while (menv)
	{
		ft_putstr(menv->name);
		write(1, "=", 1);
		ft_putendl(menv->cont);
		menv = menv->next;
	}
}
