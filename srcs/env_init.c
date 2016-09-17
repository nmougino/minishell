/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:51:11 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 20:32:55 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_extract(char **env, const char *tar)
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
	const char	*tar[6] = {"HOME", "USER", "PWD", "OLDPWD", "SHLVL", NULL};
	t_env		*menv;
	char		*cont;
	int			i;

	i = 0;
	menv = NULL;
	while (tar[i])
	{
		cont = env_extract(env, tar[i]);
		env_add(&menv, tar[i], cont);
		++i;
	}
	return (menv);
}
