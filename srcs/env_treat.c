/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 03:31:29 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 21:46:53 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*env_new(const char *name, char *cont)
{
	t_env	*new;

	if ((new = (t_env *)malloc(sizeof(t_env))))
	{
		new->name = ft_strdup(name);
		new->cont = cont;
		new->next = NULL;
	}
	return (new);
}

void			env_set(t_env *env, char *new_val)
{
	env->cont = new_val;
}

t_env			*env_get(t_env *menv, char *tar)
{
	while (menv && ft_strcmp(menv->name, tar))
		menv = menv->next;
	return (menv);
}

void			env_add(t_env **menv, const char *name, char *cont)
{
	t_env	*new;
	t_env	*cur;

	if ((new = env_new(name, cont)))
	{
		if (!(*menv))
			*menv = new;
		else
		{
			cur = *menv;
			while (cur->next)
				cur = cur->next;
			cur->next = new;
		}
	}
}

int				env_rm(t_env **menv, char *tar)
{
	t_env	*prev;
	t_env	*cur;

	if (!ft_strcmp((*menv)->name, tar))
	{
		cur = *menv;
		(*menv) = (*menv)->next;
		free_env_one(cur);
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
	free_env_one(cur);
	return (1);
}
