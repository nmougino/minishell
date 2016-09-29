/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:53:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 20:12:55 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_init_extract(t_env **menv, char *nat)
{
	size_t	i;
	char	*tmp_name;
	char	*tmp_cont;

	i = 0;
	while (nat[i] && nat[i] != '=')
		++i;
	tmp_name = ft_strndup(nat, i++);
	if (ft_strcmp(tmp_name, "SHLVL"))
		tmp_cont = ft_strdup(nat + i);
	else
		tmp_cont = ft_itoa(ft_atoi(nat + i) + 1);
	env_add(menv, tmp_name, tmp_cont);
	free(tmp_name);
	free(tmp_cont);
}

t_env		*env_init(char **native)
{
	t_env	*menv;

	menv = NULL;
	while (*native)
	{
		env_init_extract(&menv, *native);
		++native;
	}
	env_rm(&menv, "SHELL");
	if (is_env(menv, "PROMPT"))
		env_set(menv, "PROMPT", "msh.>>");
	else
		env_add(&menv, "PROMPT", "msh.>>");
	return (menv);
}
