/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 05:41:24 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/19 05:55:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	//t_env	*menv;

	(void)ac;
	(void)av;
	//menv = env_init(env);
	wheel(void);
	free_env(menv);
	return (0);
}
