/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:20:43 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/17 17:38:47 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "ft_wolf3d.h"
#include "libft.h"

static t_w	*key_rot(int key, t_w *w)
{
	double		oldxcdir;
	double		oldxp;

	oldxcdir = w->c.xcdir;
	oldxp = w->p.xp;
	if (key == 65363)
	{
		w->c.xcdir = w->c.xcdir * cos(-w->c.rot) - w->c.ycdir * sin(-w->c.rot);
		w->c.ycdir = oldxcdir * sin(-w->c.rot) + w->c.ycdir * cos(-w->c.rot);
		w->p.xp = w->p.xp * cos(-w->c.rot) - w->p.yp * sin(-w->c.rot);
		w->p.yp = oldxp * sin(-w->c.rot) + w->p.yp * cos(-w->c.rot);
	}
	if (key == 65361)
	{
		w->c.xcdir = w->c.xcdir * cos(w->c.rot) - w->c.ycdir * sin(w->c.rot);
		w->c.ycdir = oldxcdir * sin(w->c.rot) + w->c.ycdir * cos(w->c.rot);
		w->p.xp = w->p.xp * cos(w->c.rot) - w->p.yp * sin(w->c.rot);
		w->p.yp = oldxp * sin(w->c.rot) + w->p.yp * cos(w->c.rot);
	}
	return (w);
}

static int	key_hook(int key, t_w *w)
{
	mlx_destroy_image(w->mlx, w->img);
	w->img = mlx_new_image(w->mlx, IW, IH);
	w->i.data = mlx_get_data_addr(w->img, &(w->i.bpp), &(w->i.sl), &(w->i.end));
	if (key == 65307)
		exit(0);
	if (key == 65362)
	{
		if (w->m.tab[(int)(w->c.xc + w->c.xcdir * w->c.mov)][(int)w->c.yc] == 0)
			w->c.xc += w->c.xcdir * w->c.mov;
		if (w->m.tab[(int)w->c.xc][(int)(w->c.yc + w->c.ycdir * w->c.mov)] == 0)
			w->c.yc += w->c.ycdir * w->c.mov;
	}
	if (key == 65364)
	{
		if (w->m.tab[(int)(w->c.xc - w->c.xcdir * w->c.mov)][(int)w->c.yc] == 0)
			w->c.xc -= w->c.xcdir * w->c.mov;
		if (w->m.tab[(int)w->c.xc][(int)(w->c.yc - w->c.ycdir * w->c.mov)] == 0)
			w->c.yc -= w->c.ycdir * w->c.mov;
	}
	w = key_rot(key, w);
	ft_draw(*w);
	return (0);
}

static int	expose_hook(t_w *w)
{
	ft_draw(*w);
	return (0);
}

static t_w	ft_position(t_w w)
{
	int		x;
	int		y;

	x = 2;
	y = 2;
	while (w.m.tab[x])
	{
		while (w.m.tab[x][y])
		{
			if (w.m.tab[x][y] == 0)
				break ;
			++y;
		}
		if (w.m.tab[x][y] == 0)
			break ;
		++x;
	}
	if (!w.m.tab[x])
	{
		ft_putendl_fd("fail map", 2);
		exit(-1);
	}
	w.c.xc = x;
	w.c.yc = y;
	return (w);
}

int			main(int ac, char **av)
{
	t_w		w;

	if (ac != 2)
		return (-1);
	w = ft_parse_map(av, w);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, WW, WH, "wolf3d");
	w.img = mlx_new_image(w.mlx, IW, IH);
	w.i.data = mlx_get_data_addr(w.img, &(w.i.bpp), &(w.i.sl), &(w.i.end));
	mlx_key_hook(w.win, key_hook, &w);
	w = ft_position(w);
	w.c.xcdir = -1;
	w.c.ycdir = 0;
	w.p.xp = 0;
	w.p.yp = tan(((VISION / 2) * PI) / 180);
	w.draw.color = 127;
	w.c.rot = PI / 12.0;
	w.c.mov = 0.49;
	mlx_expose_hook(w.win, expose_hook, &w);
	mlx_loop(w.mlx);
	return (0);
}
