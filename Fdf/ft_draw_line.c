/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:42:41 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 19:40:51 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_fdf.h"

static void		ft_ln(t_draw *e, t_coor *coor)
{
	double		x;

	x = coor->x1;
	while (x <= coor->x2)
	{
		mlx_pixel_put(e->mlx_ptr, e->win, x,
						coor->y1 + ((coor->y2 - coor->y1)
							* (x - coor->x1)) / (coor->x2 - coor->x1),
						0x00FFFF + e->c1);
		x = x + 0.05;
	}
}

static void		ft_hv(t_draw *e, t_coor *coor)
{
	double		x;

	x = coor->x1;
	while (x <= coor->x2)
	{
		mlx_pixel_put(e->mlx_ptr, e->win, x,
						coor->y1 + ((coor->y2 - coor->y1)
							* (x - coor->x1)) / (coor->x2 - coor->x1),
						0xFF0000 + e->c2);
		x = x + 0.05;
	}
}

void			ft_coor_ver(t_draw e, int **t, int i, int j)
{
	t_coor		coor;

	coor.x1 = O + e.x + ((C + e.c) * j - (K + e.k) * (i + 1)) * (A + e.a);
	coor.y1 = O + e.y + (-1 * t[i + 1][j] * e.s + (C / 2 + e.c)
						* j + (K / 2 + e.k) * (i + 1)) * (A + e.a);
	coor.x2 = O + e.x + ((C + e.c) * j - (K + e.k) * i) * (A + e.a);
	coor.y2 = O + e.y + (-1 * t[i][j] * e.s + (C / 2 + e.c)
						* j + (K / 2 + e.k) * i) * (A + e.a);
	if (t[i][j] == 0 && t[i + 1][j] == 0)
		ft_ln(&e, &coor);
	else
		ft_hv(&e, &coor);
}

void			ft_coor_hor(t_draw e, int **t, int i, int j)
{
	t_coor		coor;

	coor.x1 = O + e.x + ((C + e.c) * j - (K + e.k) * i) * (A + e.a);
	coor.y1 = O + e.y + (-1 * t[i][j] * e.s + (C / 2 + e.c)
						* j + (K / 2 + e.k) * i) * (A + e.a);
	coor.x2 = O + e.x + ((C + e.c) * (j + 1) - (K + e.k) * i) * (A + e.a);
	coor.y2 = O + e.y + (-1 * t[i][j + 1] * e.s + (C / 2 + e.c)
						* (j + 1) + (K / 2 + e.k) * i) * (A + e.a);
	if (t[i][j] == 0 && t[i][j + 1] == 0)
		ft_ln(&e, &coor);
	else
		ft_hv(&e, &coor);
}

void			ft_key_color(int keycode, t_draw *e)
{
	e->c1 = (keycode == 49) ? e->c1 + 0x000007 : e->c1;
	e->c1 = (keycode == 50) ? e->c1 + 0x000070 : e->c1;
	e->c1 = (keycode == 51) ? e->c1 + 0x000700 : e->c1;
	e->c1 = (keycode == 52) ? e->c1 + 0x007000 : e->c1;
	e->c1 = (keycode == 53) ? e->c1 + 0x070000 : e->c1;
	e->c1 = (keycode == 54) ? e->c1 + 0x700000 : e->c1;
	e->c1 = (keycode == 55) ? e->c1 - 0x000007 : e->c1;
	e->c1 = (keycode == 56) ? e->c1 - 0x000070 : e->c1;
	e->c1 = (keycode == 57) ? e->c1 - 0x000700 : e->c1;
	e->c1 = (keycode == 48) ? e->c1 - 0x007000 : e->c1;
	e->c1 = (keycode == 45) ? e->c1 - 0x070000 : e->c1;
	e->c1 = (keycode == 61) ? e->c1 - 0x700000 : e->c1;
	e->c2 = (keycode == 65457) ? e->c2 + 0x000007 : e->c2;
	e->c2 = (keycode == 65458) ? e->c2 + 0x000070 : e->c2;
	e->c2 = (keycode == 65459) ? e->c2 + 0x000700 : e->c2;
	e->c2 = (keycode == 65460) ? e->c2 + 0x007000 : e->c2;
	e->c2 = (keycode == 65461) ? e->c2 + 0x070000 : e->c2;
	e->c2 = (keycode == 65462) ? e->c2 + 0x700000 : e->c2;
	e->c2 = (keycode == 65463) ? e->c2 - 0x000007 : e->c2;
	e->c2 = (keycode == 65464) ? e->c2 - 0x000070 : e->c2;
	e->c2 = (keycode == 65465) ? e->c2 - 0x000700 : e->c2;
	e->c2 = (keycode == 65469) ? e->c2 - 0x007000 : e->c2;
	e->c2 = (keycode == 65455) ? e->c2 - 0x070000 : e->c2;
	e->c2 = (keycode == 65450) ? e->c2 - 0x700000 : e->c2;
}
