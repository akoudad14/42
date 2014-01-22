/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 18:23:37 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/16 13:20:39 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_part(t_m *m, t_p *p, int xm, int ym)
{
	t_c		c;

	c.xp = 0;
	c.xm = (c.xm = xm) < 0 ? m->xm + c.xm : c.xm;
	c.check = 0;
	while (c.check <= 1 && c.xp < p->xp)
	{
		c.yp = 0;
		c.ym = (c.ym = ym) < 0 ? m->ym + c.ym : c.ym;
		while (c.check <= 1 && c.yp < p->yp)
		{
			if (p->piece[c.xp][c.yp] != '.'
				&& (m->map[c.xm][c.ym] == m->c
					|| m->map[c.xm][c.ym] == m->c - 32))
				c.check++;
			else if (p->piece[c.xp][c.yp] != '.'
					&& m->map[c.xm][c.ym] != '.')
				return (-1);
			++c.yp;
			c.ym = (c.ym += 1) == m->ym ? 0 : c.ym;
		}
		++c.xp;
		c.xm = (c.xm += 1) == m->xm ? 0 : c.xm;
	}
	return (c.check);
}

int				ft_place_piece(t_m *m, t_p *p)
{
	int		xm;
	int		ym;
	int		check;

	xm = 0;
	check = 0;
	while (xm <= m->xm && check != 1)
	{
		ym = 0;
		while (ym <= m->ym && check != 1)
		{
			check = ft_part(m, p, xm - p->xp, ym - p->yp);
			++ym;
		}
		++xm;
	}
	ft_putnbr(xm - p->xp - 1);
	ft_putchar(' ');
	ft_putnbr(ym - p->yp - 1);
	ft_putchar('\n');
	return (1);
}
