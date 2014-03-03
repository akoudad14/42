/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env_and_signal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:52:57 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/03 15:07:11 by makoudad         ###   ########.fr       */
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

int				ft_check_signal(void)
{
	signal(SIGINT, catch_sign);
	signal(SIGQUIT, catch_sign);
	signal(SIGTSTP, catch_sign);
	return (1);
}
