/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 04:42:30 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/27 22:15:25 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_env_disp(t_env *env, char *conv)
{
	int		i;
	char	*tar;

	i = 0;
	tar = ft_strdup(conv);
	while (env && ft_strcmp(env->name, tar))
		env = env->next;
	free(tar);
	if (env)
		ft_putstr(env->cont);
}

static void	echo_prompt(t_env *env, char *conv)
{
	int	i;

	i = 0;
	while (conv[i] && conv[i] != '$')
	{
		write(1, conv + i, 1);
		++i;
	}
	if (conv[i] == '$')
	{
		if (conv[i + 1])
			echo_env_disp(env, conv + i + 1);
		else
			write(1, "$", 1);
	}
}

void		bi_echo(t_env *env, char **com)
{
	char	n;
	int		i;

	n = (com[1] && !ft_strcmp(com[1], "-n")) ? 2 : 1;
	i = n;
	while (com[i])
	{
		echo_prompt(env, com[i]);
		++i;
		if (com[i])
			write(1, " ", 1);
	}
	if (!(n - 1))
		write(1, "\n", 1);
}
