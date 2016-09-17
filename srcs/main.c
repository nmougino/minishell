/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:00:48 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/17 22:21:08 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static void	mwheel(t_env *menv)
{
	char	*line;

	(void)menv;
	get_next_line(0, &line);
	while(ft_strcmp("exit", line))
	{
		free(line);
		get_next_line(0, &line);
	}
	free(line);
}

int		main(int ac, char **av, char **env)
{
	t_env	*menv;

	(void)ac;
	(void)av;
	menv = env_init(env);
	mwheel(menv);
	free_env(menv);
	return (0);
}

/*
int	main(int ac, char **av, char **env)
{
	int		p;

	(void)ac;
	(void)av;
	p = 0;
	while (env[p])
		ft_putendl(env[p++]);
	return (0);
}

int	main(int ac, char **av)
{
	int		p;

	(void)ac;
	p = 0;
	while (av[p])
		ft_putendl(av[p++]);
	++p;
	while (av[p])
		ft_putendl(av[p++]);
	return (0);
}
*/

/*
		EXEMPLE
void	enfant(char **av)
{
	printf("salut c'est le process enfant\n%s\n", av[1]);
	execve(av[1], &av[2], NULL);
}

int main(int ac, char **av)
{
	pid_t	bu;

	bu = fork();
	if (!bu)
	{
		printf("process parent\n");
		wait(0);
	}
	else
	{
		printf("process fille\n");
		enfant(av);
	}
	return (0);
}
*/
