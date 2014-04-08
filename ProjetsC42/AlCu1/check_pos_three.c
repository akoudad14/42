/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 11:37:10 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 12:46:55 by tibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pow4.h"

int			ft_check_pos_hor_three(t_pow p, int x, int y)
{
	if (y + 3 < p.col
		&& ft_c_q(p.player, p.game[x][y + 1],
					p.game[x][y + 2], p.game[x][y + 3]) == 0)
		return (0);
	if (y > 0 && y + 2 < p.col
		&& ft_c_q(p.player, p.game[x][y - 1],
					p.game[x][y + 1], p.game[x][y + 2]) == 0)
		return (0);
	if (y > 1 && y + 1 < p.col
		&& ft_c_q(p.player, p.game[x][y - 2],
					p.game[x][y - 1], p.game[x][y + 1]) == 0)
		return (0);
	if (y > 2
		&& ft_c_q(p.player, p.game[x][y - 3],
					p.game[x][y - 2], p.game[x][y - 1]) == 0)
		return (0);
	return (-1);
}

int			ft_check_pos_diag1_three(t_pow p, int x, int y)
{
	if (x + 3 < p.line && y + 3 < p.col
		&& ft_c_q(p.player, p.game[x + 1][y + 1],
					p.game[x + 2][y + 2], p.game[x + 3][y + 3]) == 0)
		return (0);
	if (x > 0 && y > 0 && x + 2 < p.line && y + 2 < p.col
		&& ft_c_q(p.player, p.game[x - 1][y - 1],
					p.game[x + 1][y + 1], p.game[x + 2][y + 2]) == 0)
		return (0);
	if (x > 1 && y > 1 && x + 1 < p.line && y + 1 < p.col
		&& ft_c_q(p.player, p.game[x - 2][y - 2],
					p.game[x - 1][y - 1], p.game[x + 1][y + 1]) == 0)
		return (0);
	if (x > 2 && y > 2
		&& ft_c_q(p.player, p.game[x - 1][y - 1],
					p.game[x - 2][y - 2], p.game[x - 3][y - 3]) == 0)
		return (0);
	return (-1);
}

int			ft_check_pos_diag2_three(t_pow p, int x, int y)
{
	if (x > 2 && y + 3 < p.col
		&& ft_c_q(p.player, p.game[x - 1][y + 1],
					p.game[x - 2][y + 2], p.game[x - 3][y + 3]) == 0)
		return (0);
	if (x > 1 && x + 1 < p.line && y > 0 && y + 2 < p.col
		&& ft_c_q(p.player, p.game[x + 1][y - 1],
					p.game[x - 1][y + 1], p.game[x - 2][y + 2]) == 0)
		return (0);
	if (x > 0 && x + 2 < p.line && y > 1 && y + 1 < p.col
		&& ft_c_q(p.player, p.game[x + 2][y - 2],
					p.game[x + 1][y - 1], p.game[x - 1][y + 1]) == 0)
		return (0);
	if (x + 3 < p.line && y > 2
		&& ft_c_q(p.player, p.game[x + 3][y - 3],
					p.game[x + 2][y - 2], p.game[x + 1][y - 1]) == 0)
		return (0);
	return (-1);
}

int			ft_check_next_turn(t_pow p, int x, int y, int flag)
{
	char	rem;

	rem = p.player;
	if (flag > 0)
		p.player = (p.player == 'O') ? 'X' : 'O';
	if (x > 0 && ft_check_pos_hor_three(p, x - 1, y) == 0)
		return (-1);
	if (x > 0 && ft_check_pos_diag1_three(p, x - 1, y) == 0)
		return (-1);
	if (x > 0 && ft_check_pos_diag2_three(p, x - 1, y) == 0)
		return (-1);
	p.player = rem;
	return (0);
}

int			ft_check_three(t_pow p, int x, int y)
{
	if (ft_check_pos_hor_three(p, x, y) == 0)
		return (0);
	if (x + 3 < p.line
		&& ft_c_q(p.player, p.game[x + 1][y],
					p.game[x + 2][y], p.game[x + 3][y]) == 0)
		return (0);
	if (ft_check_pos_diag1_three(p, x, y) == 0)
		return (0);
	if (ft_check_pos_diag2_three(p, x, y) == 0)
		return (0);
	return (-1);
}
