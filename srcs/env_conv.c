/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 23:38:09 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/26 20:19:36 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_env_len(t_env *env)
{
	size_t	len;

	len = 0;
	while (env)
	{
		++len;
		env = env->next;
	}
	return (len);
}

char	**env_conv(t_env *menv)
{
	char	**ans;
	size_t	len;
	int		i;

	i = 0;
	len = get_env_len(menv) + 1;
	ans = (char **)malloc(sizeof(char *) * len);
	while (menv)
	{
		ans[i] = ft_strnew(sizeof(char) *
			(ft_strlen(menv->name) + ft_strlen(menv->cont) + 1));
		ft_strcpy(ans[i], menv->name);
		ft_strcat(ans[i], "=");
		ft_strcat(ans[i], menv->cont);
		++i;
		menv = menv->next;
	}
	ans[i] = NULL;
	return (ans);
}
