/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_virtual_play.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:20:29 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 13:15:57 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pow4.h"

int		ft_check_pos(t_pow p, int x, int y, int flag)
{
	if (flag == 3)
		return (ft_check_three(p, x, y));
	else if ((flag == 2 || flag == -2)
			&& ft_check_next_turn(p, x, y, flag) == 0)
		return (ft_check_two(p, x, y, flag));
	else if ((flag == 1 || flag == -1)
			&& ft_check_next_turn(p, x, y, flag) == 0)
	{
		if (y + 1 < p.col && p.player == p.game[x][y + 1])
			return (0);
		if (x + 1 < p.line && p.player == p.game[x + 1][y])
			return (0);
		if (x + 1 < p.line && y + 1 < p.col && p.player == p.game[x + 1][y + 1])
			return (0);
		if (x + 1 < p.line && y > 0	&& p.player == p.game[x + 1][y - 1])
			return (0);
		if (x > 0 && y + 1 < p.col && p.player == p.game[x - 1][y + 1])
			return (0);
		if (x > 0 && y > 0 && p.player == p.game[x - 1][y - 1])
			return (0);
	}
	return (-1);
}

int		ft_finish_check_pieces(t_pow pow, int flag, int i)
{
	int		j;

	while (pow.game[i])
	{
		j = 0;
		while (pow.game[i][j])
		{
			if (flag != 0 && flag != 4 && pow.game[i][j] == '*')
			{
				if (ft_check_pos(pow, i, j, flag) == 0)
					return (j);
			}
			else if (flag == 4 && pow.game[i][j] == '*'
						&& ft_check_next_turn(pow, i, j, flag) == 0)
				return (j);
			else if (flag == 0 && pow.game[i][j] == '*')
				return (j);
			++j;
		}
		++i;
	}
	return (-1);
}

int		ft_check_pieces(t_pow pow, int flag)
{
	int		i;
	int		j;

	i = 0;
	while (pow.game[i] && pow.game[i + 1])
	{
		j = 0;
		while (pow.game[i][j] && pow.game[i + 1][j])
		{
			if (flag != 0 && flag != 4
				&& pow.game[i][j] == '*' && pow.game[i + 1][j] != '*')
			{
				if (ft_check_pos(pow, i, j, flag) == 0)
					return (j);
			}
			else if (flag == 4 && pow.game[i][j] == '*'
						&& ft_check_next_turn(pow, i, j, flag) == 0)
				return (j);
			else if (flag == 0 && pow.game[i][j] == '*')
				return (j);
			++j;
		}
		++i;
	}
	return (ft_finish_check_pieces(pow, flag, i));
}

int		ft_virtual_play(t_pow pow, int nb_turn)
{
	int		col_ch;
	char	rem;

	if (nb_turn == 0 && pow.col % 2 == 1)
		return ((pow.col / 2) + 1);
	else if (nb_turn == 0)
		return (pow.col / 2);
	col_ch = ft_check_pieces(pow, 3);
	rem = pow.player;
	pow.player = (pow.player == 'O') ? 'X' : 'O';
	col_ch = (col_ch == -1) ? ft_check_pieces(pow, 3) : col_ch;
	pow.player = rem;
	col_ch = (col_ch == -1) ? ft_check_pieces(pow, 2) : col_ch;
	pow.player = (pow.player == 'O') ? 'X' : 'O';
	col_ch = (col_ch == -1 && pow.mode > 1) ? ft_check_pieces(pow, -2) : col_ch;
	pow.player = rem;
	col_ch = (col_ch == -1 && pow.mode > 1) ? ft_check_pieces(pow, 1) : col_ch;
	pow.player = (pow.player == 'O') ? 'X' : 'O';
	col_ch = (col_ch == -1 && pow.mode > 2) ? ft_check_pieces(pow, -1) : col_ch;
	pow.player = rem;
	col_ch = (col_ch == -1) ? ft_check_pieces(pow, 4) : col_ch;
	col_ch = (col_ch == -1) ? ft_check_pieces(pow, 0) : col_ch;
	return (col_ch + 1);
}
