/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcsbi_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:58:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 00:00:08 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_env(t_env *menv)
{
	while (menv)
	{
		ft_putstr(menv->name);
		write(1, "=", 1);
		ft_putendl(menv->cont);
		menv = menv->next;
	}
}
