/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:16:22 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/26 22:36:12 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	path_cpy(char *exe, char *path, char **ans)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	while (path[len] && path[len] != ':')
		++len;
	*ans = ft_strnew(len + 1 + ft_strlen(exe));
	i = 0;
	while (i < len)
	{
		(*ans)[i] = path[i];
		++i;
	}
	(*ans)[i] = '/';
	++i;
	j = 0;
	while (exe[j])
		(*ans)[i++] = exe[j++];
	return (len);
}

char			*get_exe(char *path, char *exe)
{
	size_t		len;
	struct stat	buf;
	char		*ans;

	len = 0;
	ans = NULL;
	if (ft_strchr(exe, '/') && !lstat(exe, &buf))
		return (ft_strdup(exe));
	else if (path && !ft_strchr(exe, '/'))
	{
		len = path_cpy(exe, path, &ans);
		while (*path && lstat(ans, &buf))
		{
			free(ans);
			ans = NULL;
			path += len;
			if (*path)
				len = path_cpy(exe, ++path, &ans);
		}
	}
	return (ans);
}
