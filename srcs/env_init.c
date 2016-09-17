/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:51:11 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 19:05:50 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_extract(char **env, char *tar)
{
	char	*ans;
	size_t	len;

	len = ft_strlen(tar);
	while (ft_strncmp(*env, tar, len))
		++env;
	ans = ft_strdup((*env) + len + 1);
	return (ans);
}

t_env		*env_init(char **env)
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
