/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:51:11 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/19 02:06:59 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_extract(char **env, const char *tar)
{
	size_t	len;

	len = ft_strlen(tar);
	while (ft_strncmp(*env, tar, len))
		++env;
	if (env)
		return ((*env) + len + 1);
	return (NULL);
}

static void	shlvl_init(t_env *menv)
{
	t_env	*tar;

	tar = env_get(menv, "SHLVL");
	env_set(tar, ft_itoa(ft_atoi(tar->cont) + 1));
}

t_env		*env_init(char **env)
{
	const char	*tar[7] = {"HOME", "USER", "PWD", "OLDPWD", "SHLVL", "PATH", NULL};
	t_env		*menv;
	int			i;

	i = 0;
	menv = NULL;
	while (tar[i])
	{
		env_add(&menv, tar[i], env_extract(env, tar[i]));
		++i;
	}
	env_add(&menv, "PROMPT", "minishell: ");
	shlvl_init(menv);
	return (menv);
}
