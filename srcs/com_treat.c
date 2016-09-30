/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:41:12 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/01 00:24:27 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	com_rep_quote(char *c)
{
	if (*c == -1 || *c == '"')
		*c = ' ';
}

static void	com_quote_iter(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			if (ft_strchr(line + i + 1, '"'))
			{
				j = i;
				while (line[++j] != '"')
					if (line[j] == ' ')
						line[j] = -1;
			}
			line[i] = ' ';
		}
		++i;
	}
}

static char	*com_tilde_create(char *tmp, t_env *menv)
{
	int		i;
	int		nb;

	nb = 0;
	i = -1;
	while (tmp[++i])
		if (tmp[i] == '~')
			++nb;
	return (ft_strnew(ft_strlen(tmp)
		+ (size_t)nb * (ft_strlen(env_get(menv, "HOME")) - 1)));
}

static void	com_tilde_treat(char **com, t_env *menv)
{
	int		i;
	int		nb;
	char	*str;
	char	*tmp;

	tmp = *com;
	if ((str = com_tilde_create(*com, menv)))
	{
		i = -1;
		nb = 0;
		while (tmp[++i])
		{
			if (tmp[i] == '~')
			{
				ft_strcat(str, env_get(menv, "HOME"));
				nb += ft_strlen(env_get(menv, "HOME"));
			}
			else
				str[nb++] = tmp[i];
		}
		free(tmp);
		*com = str;
	}
}

char		**com_treat(char *line, t_env *menv)
{
	int		i;
	char	**ans;

	if (!ft_strchr(line, '~') && !ft_strchr(line, '"'))
		return (ft_strsplit(line, ' '));
	com_quote_iter(line);
	if (!(ans = ft_strsplit(line, ' ')))
		return (NULL);
	i = 0;
	while (ans[i])
	{
		ft_striter(ans[i], com_rep_quote);
		++i;
	}
	i = -1;
	if (is_env(menv, "HOME"))
		while (ans[++i])
			if (ft_strchr(ans[i], '~'))
				com_tilde_treat(ans + i, menv);
	menv = NULL;
	return (ans);
}
