/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:26:56 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/17 16:43:28 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_WOLF3D_H
# define	FT_WOLF3D_H

# define	WW				812.0
# define	WH				684.0
# define	IW				812.0
# define	IH				684.0
# define	VISION			66
# define	PI				3.141592653589

# include	<math.h>
# include	<string.h>
# include	<stdlib.h>
# include	<mlx.h>
# include	"libft.h"

typedef struct	s_c
{
	double		xc;
	double		yc;
	double		xcdir;
	double		ycdir;
	int			xmap;
	int			ymap;
	double		vis;
	double		mov;
	double		rot;
}				t_c;

typedef struct	s_p
{
	double		xp;
	double		yp;
}				t_p;

typedef struct	s_r
{
	double		xr;
	double		yr;
	double		xrdir;
	double		yrdir;
}				t_r;

typedef struct	s_m
{
	int			**tab;
	int			lin;
	int			col;
}				t_m;

typedef struct	s_i
{
	char		*data;
	int			bpp;
	int			sl;
	int			end;
}				t_i;

typedef struct	s_dist
{
	double		firstinterX;
	double		firstinterY;
	double		cstinterX;
	double		cstinterY;
	double		distwall;
}				t_dist;

typedef struct	s_draw
{
	int			start;
	int			end;
	int			color;
	int			helpcol;
}				t_draw;

typedef struct	s_step
{
	int			stepx;
	int			stepy;
}				t_step;

typedef struct	s_w
{
	void		*mlx;
	void		*win;
	void		*img;
	t_c			c;
	t_p			p;
	t_r			r;
	t_m			m;
	t_i			i;
	t_dist		dist;
	t_draw		draw;
	t_step		step;
}				t_w;

void		ft_draw(t_w w);
void		ft_draw_finish(t_w w);
void		ft_draw_line(t_w w, int x);
t_w			ft_parse_map(char **av, t_w w);

#endif	/* !FT_WOLF3D_H */
