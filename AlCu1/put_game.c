/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:05:53 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 14:40:54 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pow4.h"
#include "libft.h"

void		ft_print_col(t_pow pow, int col_ch)
{
	int		i;

	ft_putstr("\033[36m");
	i = -1;
	while (pow.game[0][++i])
	{
		ft_putnbr((i + 1) % 10);
		ft_putstr("  ");
	}
	ft_putstr("\033[0m");
	ft_putchar('\n');
	if (col_ch != -1 && pow.mode != 3)
	{
		ft_putstr("Last shot at column ");
		ft_putstr("\033[35m");
		ft_putnbr(col_ch);
		ft_putstr("\033[0m");
		ft_putchar('\n');
	}
}

void		ft_put_game(t_pow pow, int col_ch)
{
	int		i;
	int		j;

	ft_putchar('\n');
	i = -1;
	while (pow.game[++i])
	{
		j = -1;
		while (pow.game[i][++j])
		{
			if (pow.game[i][j] == 'X')
				ft_putstr("\033[33m");
			else if (pow.game[i][j] == 'O')
				ft_putstr("\033[31m");
			ft_putchar(pow.game[i][j]);
			ft_putstr("\033[0m");
			ft_putstr("  ");
		}
		ft_putchar('\n');
	}
	ft_print_col(pow, col_ch);
}
