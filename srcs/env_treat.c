/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 03:31:29 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 18:27:19 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*env_new(char *name, char *cont)
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

char	*env_extract(char **env, char *tar)
{
	char	*ans;
	size_t	len;

	len = ft_strlen(tar);
	while (ft_strncmp(*env, tar, len))
		++env;
	ans = ft_strdup((*env) + len + 1);
	return (ans);
}

void	env_add(t_env **menv, char *name, char *cont)
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

t_env	*env_init(char **env)
{
	t_env	*menv;
	char	*cont;

	menv = NULL;
	cont = env_extract(env, "PWD");
	env_add(&menv, "PWD", cont);
	cont = env_extract(env, "HOME");
	env_add(&menv, "HOME", cont);
	cont = env_extract(env, "LOGNAME");
	env_add(&menv, "LOGNAME", cont);
	return (menv);
}
