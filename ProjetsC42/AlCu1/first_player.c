/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:38:14 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 15:34:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "libft.h"

char			ft_first_player(void)
{
	int			res;
	time_t		tloc;
	char		player;

	srand(time(&tloc));
	res = rand();
	player = res % 2 == 1 ? 'O' : 'X';
	ft_putstr("\033[1m");
	if (player == 'O')
		ft_putstr("The computer starts the game.\n");
	else
		ft_putstr("The player starts the game.\n");
	ft_putstr("\033[0m");
	return (player);
}
