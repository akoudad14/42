/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 10:53:02 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 19:51:36 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "ft_fdf.h"

static void		ft_line_hor(t_draw e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e.nb_line)
	{
		j = 0;
		while (j < e.nb_col - 1)
		{
			ft_coor_hor(e, e.tab, i, j);
			j++;
		}
		i++;
	}
}

static void		ft_line_ver(t_draw e)
{
	int		i;
	int		j;

	j = 0;
	while (j < e.nb_col)
	{
		i = 0;
		while (i < e.nb_line - 1)
		{
			ft_coor_ver(e, e.tab, i, j);
			i++;
		}
		j++;
	}
}

static int		expose_hook(t_draw *e)
{
	ft_line_hor(*e);
	ft_line_ver(*e);
	return (0);
}

static int		key_hook(int keycode, t_draw *e)
{
	if (keycode == 65307)
		exit(0);
	e->a = (keycode == 65362) ? e->a + 0.25 : e->a;
	e->a = (keycode == 65364) ? e->a - 0.25 : e->a;
	e->c = (keycode == 97) ? e->c - 1 : e->c;
	e->c = (keycode == 100) ? e->c + 1 : e->c;
	e->k = (keycode == 119) ? e->k - 1 : e->k;
	e->k = (keycode == 115) ? e->k + 1 : e->k;
	e->x = (keycode == 39) ? e->x + 20 : e->x;
	e->x = (keycode == 108) ? e->x - 20 : e->x;
	e->y = (keycode == 112) ? e->y - 20 : e->y;
	e->y = (keycode == 59) ? e->y + 20 : e->y;
	e->s = (keycode == 65451) ? e->s + 0.5 : e->s;
	e->s = (keycode == 65453) ? e->s - 0.5 : e->s;
	ft_key_color(keycode, e);
	mlx_clear_window(e->mlx_ptr, e->win);
	ft_line_hor(*e);
	ft_line_ver(*e);
	return (0);
}

void			ft_draw_grid(int nb_line, int nb_col, int **tab)
{
	t_draw	e;

	e.mlx_ptr = mlx_init();
	e.win = mlx_new_window(e.mlx_ptr, 1500, 1500, "FdF");
	e.nb_line = nb_line;
	e.nb_col = nb_col;
	e.tab = tab;
	e.a = 1;
	e.c = 1;
	e.k = 1;
	e.x = 1;
	e.y = 1;
	e.c1 = 0x000000;
	e.c2 = 0x000000;
	e.s = 1;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx_ptr);
}
