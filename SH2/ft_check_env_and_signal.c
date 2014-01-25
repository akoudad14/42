/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env_and_signal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:52:57 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 19:22:23 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

static void		catch_sign(int sign)
{
	if (sign == SIGINT || sign == SIGQUIT || sign == SIGTSTP)
	{
		ft_putchar('\n');
		ft_putstr("42makoudad$> ");
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
