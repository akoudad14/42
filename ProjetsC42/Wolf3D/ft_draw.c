/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 18:40:16 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/17 16:41:20 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf3d.h"

static t_w		ft_coor_col(t_w w, int sizewall, int x)
{
	w.draw.start = ((w.draw.start = -sizewall / 2 + WH / 2) < 0)
		? 0 : w.draw.start;
	w.draw.end = ((w.draw.end = sizewall / 2 + WH / 2) >= WH)
		? WH - 1 : w.draw.end;
	ft_draw_line(w, x);
	return (w);
}

static t_w		ft_next(t_w w, int x, int wall)
{
	int		sizewall;

	while (wall == 0)
	{
		if (w.dist.firstinterX < w.dist.firstinterY)
		{
			w.dist.firstinterX += w.dist.cstinterX;
			w.c.xmap += w.step.stepx;
			w.draw.helpcol = (w.r.xrdir >= 0) ? 0 : 1;
		}
		else
		{
			w.dist.firstinterY += w.dist.cstinterY;
			w.c.ymap += w.step.stepy;
			w.draw.helpcol = (w.r.yrdir >= 0) ? 2 : 3;
		}
		wall = (w.m.tab[w.c.xmap][w.c.ymap] > 0) ? 1 : 0;
	}
	w.dist.distwall = (w.draw.helpcol == 0 || w.draw.helpcol == 1)
		? ft_fabs((w.c.xmap - w.r.xr + (1 - w.step.stepx) / 2) / w.r.xrdir)
		: ft_fabs((w.c.ymap - w.r.yr + (1 - w.step.stepy) / 2) / w.r.yrdir);
	sizewall = ft_abs((int)(IH / w.dist.distwall));
	ft_coor_col(w, sizewall, x);
	return (w);
}

static t_w		ft_init_dist(t_w w)
{
	w.dist.cstinterY
		= sqrt(1 + (w.r.xrdir * w.r.xrdir) / (w.r.yrdir * w.r.yrdir));
	w.dist.cstinterX
		= sqrt(1 + (w.r.yrdir * w.r.yrdir) / (w.r.xrdir * w.r.xrdir));
	if (w.r.xrdir < 0)
	{
		w.dist.firstinterX = (w.r.xr - w.c.xmap) * w.dist.cstinterX;
		w.step.stepx = -1;
	}
	else
	{
		w.dist.firstinterX = (w.c.xmap + 1.0 - w.r.xr) * w.dist.cstinterX;
		w.step.stepx = 1;
	}
	if (w.r.yrdir < 0)
	{
		w.dist.firstinterY = (w.r.yr - w.c.ymap) * w.dist.cstinterY;
		w.step.stepy = -1;
	}
	else
	{
		w.dist.firstinterY = (w.c.ymap + 1.0 - w.r.yr) * w.dist.cstinterY;
		w.step.stepy = 1;
	}
	return (w);
}

void			ft_draw(t_w w)
{
	int		x;
	int		wall;

	x = 0;
	wall = 0;
	while (x < IW)
	{
		wall = 0;
		w.c.vis = 2 * x / IW - 1;
		w.r.xr = w.c.xc;
		w.r.yr = w.c.yc;
		w.r.xrdir = w.c.xcdir + w.p.xp * w.c.vis;
		w.r.yrdir = w.c.ycdir + w.p.yp * w.c.vis;
		w.c.xmap = (int)w.r.xr;
		w.c.ymap = (int)w.r.yr;
		w = ft_init_dist(w);
		w = ft_next(w, x, wall);
		x++;
	}
	ft_draw_finish(w);
	mlx_put_image_to_window(w.mlx, w.win, w.img, 0, 0);
}
