/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:00:48 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/16 01:57:17 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	return (0);
}

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
