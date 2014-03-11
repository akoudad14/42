/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:57:58 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 12:46:01 by tibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pow4.h"

int		ft_c_q(char p1, char p2, char p3, char p4)
{
	if (p1 != '*' && p1 == p2 && p1 == p3 && p1 == p4)
		return (0);
	return (-1);
}

int		ft_check_pos_hor(t_pow p, int x, int y)
{
	if (y + 3 < p.col
		&& ft_c_q(p.game[x][y], p.game[x][y + 1],
					p.game[x][y + 2], p.game[x][y + 3]) == 0)
		return (0);
	if (y > 0 && y + 2 < p.col
		&& ft_c_q(p.game[x][y], p.game[x][y - 1],
					p.game[x][y + 1], p.game[x][y + 2]) == 0)
		return (0);
	if (y > 1 && y + 1 < p.col
		&& ft_c_q(p.game[x][y], p.game[x][y - 2],
					p.game[x][y - 1], p.game[x][y + 1]) == 0)
		return (0);
	if (y > 2 && ft_c_q(p.game[x][y], p.game[x][y - 3],
						p.game[x][y - 2], p.game[x][y - 1]) == 0)
		return (0);
	return (-1);
}

int		ft_check_pos_diag1(t_pow p, int x, int y)
{
	if (x + 3 < p.line && y + 3 < p.col
		&& ft_c_q(p.game[x][y], p.game[x + 1][y + 1],
					p.game[x + 2][y + 2], p.game[x + 3][y + 3]) == 0)
		return (0);
	if (x > 0 && y > 0 && x + 2 < p.line && y + 2 < p.col
		&& ft_c_q(p.game[x][y], p.game[x - 1][y - 1],
					p.game[x + 1][y + 1], p.game[x + 2][y + 2]) == 0)
		return (0);
	if (x > 1 && y > 1 && x + 1 < p.line && y + 1 < p.col
		&& ft_c_q(p.game[x][y], p.game[x - 2][y - 2],
					p.game[x - 1][y - 1], p.game[x + 1][y + 1]) == 0)
		return (0);
	if (x > 2 && y > 2
		&& ft_c_q(p.game[x][y], p.game[x - 1][y - 1],
					p.game[x - 2][y - 2], p.game[x - 3][y - 3]) == 0)
		return (0);
	return (-1);
}

int		ft_check_pos_diag2(t_pow p, int x, int y)
{
	if (x > 2 && y + 3 < p.col
		&& ft_c_q(p.game[x][y], p.game[x - 1][y + 1],
					p.game[x - 2][y + 2], p.game[x - 3][y + 3]) == 0)
		return (0);
	if (x > 1 && x + 1 < p.line && y > 0 && y + 2 < p.col
		&& ft_c_q(p.game[x][y], p.game[x + 1][y - 1],
					p.game[x - 1][y + 1], p.game[x - 2][y + 2]) == 0)
		return (0);
	if (x > 0 && x + 2 < p.line && y > 1 && y + 1 < p.col
		&& ft_c_q(p.game[x][y], p.game[x + 2][y - 2],
					p.game[x + 1][y - 1], p.game[x - 1][y + 1]) == 0)
		return (0);
	if (x + 3 < p.line && y > 2
		&& ft_c_q(p.game[x][y], p.game[x + 3][y - 3],
					p.game[x + 2][y - 2], p.game[x + 1][y - 1]) == 0)
		return (0);
	return (-1);
}

int		ft_check_alignment(t_pow p, int x, int y)
{
	int		res;

	res = -1;
	if (x < 0 || y < 0)
		return (res);
	if (ft_check_pos_hor(p, x, y) == 0)
		return (0);
	if (x + 3 < p.line
		&& ft_c_q(p.game[x][y], p.game[x + 1][y],
					p.game[x + 2][y], p.game[x + 3][y]) == 0)
		return (0);
	if (ft_check_pos_diag1(p, x, y) == 0)
		return (0);
	if (ft_check_pos_diag2(p, x, y) == 0)
		return (0);
	return (res);
}
