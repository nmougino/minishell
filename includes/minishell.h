/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:02:17 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/21 17:16:37 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct		s_env
{
	char			*name;
	char			*cont;
	struct s_env	*next;
}					t_env;

void				env_del_one(t_env *elem);

#endif
