/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 11:42:44 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 12:50:11 by tibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pow4.h"

int			ft_check_pos_hor_two(t_pow p, int x, int y, int flag)
{
	if (y + 2 < p.col
		&& ft_c_q(p.player, p.game[x][y + 1], p.game[x][y + 2], p.player) == 0
		&& (flag < 0 || (flag > 0
							&& ((y > 0 && p.game[x][y - 1] == '*')
							|| (y + 3 < p.col && p.game[x][y + 3] == '*')))))
		return (0);
	if (y > 0 && y + 1 < p.col
		&& ft_c_q(p.player, p.game[x][y - 1], p.game[x][y + 1], p.player) == 0
		&& (flag < 0 || (flag > 0
							&& ((y > 1 && p.game[x][y - 2] == '*')
							|| (y + 2 < p.col && p.game[x][y + 2] == '*')))))
		return (0);
	if (y > 1
		&& ft_c_q(p.player, p.game[x][y - 2], p.game[x][y - 1], p.player) == 0
		&& (flag < 0 || (flag > 0
							&& ((y > 2 && p.game[x][y - 3] == '*')
							|| (y + 1 < p.col && p.game[x][y + 1] == '*')))))
		return (0);
	return (-1);
}

int			ft_check_pos_diag1_two(t_pow p, int x, int y, int f)
{
	if (x + 2 < p.line && y + 2 < p.col
		&& ft_c_q(p.player, p.game[x + 1][y + 1],
					p.game[x + 2][y + 2], p.player) == 0
		&& (f < 0 || (f > 0
						&& ((y + 3 < p.col && x + 3 < p.line
						&& p.game[x + 3][y + 3] == '*')
						|| (y > 0 && x > 0 && p.game[x - 1][y - 1] == '*')))))
		return (0);
	if (x > 0 && y > 0 && x + 1 < p.line && y + 1 < p.col
		&& ft_c_q(p.player, p.game[x - 1][y - 1],
					p.game[x + 1][y + 1], p.player) == 0
		&& (f < 0 || (f > 0
						&& ((y + 2 < p.col && x + 2 < p.line
						&& p.game[x + 2][y + 2] == '*')
						|| (y > 1 && x > 1 && p.game[x - 2][y - 2] == '*')))))
		return (0);
	if (x > 1 && y > 1
		&& ft_c_q(p.player, p.game[x - 2][y - 2],
					p.game[x - 1][y - 1], p.player) == 0
		&& (f < 0 || (f > 0
						&& ((y + 1 < p.col && x + 1 < p.line
						&& p.game[x + 1][y + 1] == '*')
						|| (y > 2 && x > 2 && p.game[x - 3][y - 3] == '*')))))
		return (0);
	return (-1);
}

int			ft_check_pos_diag2_two2(t_pow p, int x, int y, int f)
{
	if (x > 0 && x + 1 < p.line && y > 0 && y + 1 < p.col
		&& ft_c_q(p.player, p.game[x + 1][y - 1],
					p.game[x - 1][y + 1], p.player) == 0
		&& (f < 0 || (f > 0
						&& ((y + 2 < p.col && x < 2
						&& p.game[x - 2][y + 2] == '*')
						|| (y > 2 && x + 2 < p.line
						&& p.game[x + 1][y - 2] == '*')))))
		return (0);
	if (x + 2 < p.line && y > 1
			&& ft_c_q(p.player, p.game[x + 2][y - 2],
						p.game[x + 1][y - 1], p.player) == 0
		&& (f < 0 || (f > 0  && ((y < 3 && x + 3 < p.line
								&& p.game[x + 3][y - 3] == '*')
								|| (y + 1 > p.col && x > 0
								&& p.game[x - 1][y + 1] == '*')))))
		return (0);
	return (-1);
}

int			ft_check_pos_diag2_two(t_pow p, int x, int y, int f)
{
	if (x > 2 && y + 2 < p.col
			&& ft_c_q(p.player, p.game[x - 1][y + 1],
						p.game[x - 2][y + 2], p.player) == 0
		&& (f < 0 || (f > 0 && ((y + 3 < p.col && x > 2
							&& p.game[x - 3][y + 3] == '*')
							|| (y > 0 && x + 1 < p.line
							&& p.game[x + 1][y - 1] == '*')))))
		return (0);
	if (ft_check_pos_diag2_two2(p, x, y, f) == 0)
		return (0);
	return (-1);
}

int			ft_check_two(t_pow p, int x, int y, int flag)
{
	if (ft_check_pos_hor_two(p, x, y, flag) == 0)
		return (0);
	if (x + 2 < p.line
		&& ft_c_q(p.player, p.player, p.game[x + 1][y],
					p.game[x + 2][y]) == 0 && x > 0)
		return (0);
	if (ft_check_pos_diag1_two(p, x, y, flag) == 0)
		return (0);
	if (ft_check_pos_diag2_two(p, x, y, flag) == 0)
		return (0);
	return (-1);
}
