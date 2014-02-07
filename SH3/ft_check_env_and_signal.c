/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env_and_signal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:52:57 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 19:10:44 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "libft.h"

static void		catch_sign(int sign)
{
	if (sign == SIGINT)
	{
		ft_putstr_fd("\n_$> ", 1);
		return ;
	}
}

int				ft_check_env_and_signal(char **env)
{
	if (!env[0])
	{
		ft_putendl_fd("Warning: env empty", 2);
		return (0);
	}
	signal(SIGINT, catch_sign);
	signal(SIGQUIT, catch_sign);
	signal(SIGTSTP, catch_sign);
	return (1);
}
