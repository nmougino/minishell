/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:16:22 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/25 18:14:00 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_exe(char *pathes, char *exe)
{
	int			len;
	struct stat	buf;

	len = 0;
	pathes = NULL;
	//verifie qu'il ne s'agit pas d'un local
	if (ft_strchr(exe, '/') && !lstat(exe, &buf))
		return (ft_strdup(exe));
	return (NULL);
}
