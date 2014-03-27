/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:02:27 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 12:25:59 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "rt.h"
#include "libft.h"




#include <stdio.h>

double	ft_mix(double a, double b, double mix)
{
	return (b * mix + a * (1 - mix));
}

int		ft_init_save_and_ray(t_r *r, t_save *save)
{
	r->t0 = MAX;
	r->t1 = MAX;
	r->tnear = MAX;
	save->i = -1;
	save->j = -1;
	return (0);
}

t_c		ft_trace(t_obj obj, t_r *r, t_save *save)
{
	int			i;
	int			j;
	t_c			color;//ATTENTION !!!!!!! Il faut l'initialiser dans chaque treatment

	ft_init_save_and_ray(r, save);
	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj.nb[i])
		{
//printf("%f, %f, %f\n", (((t_sph ***)obj.type)[i][j])->c.x, (((t_sph ***)obj.type)[i][j])->c.y, (((t_sph ***)obj.type)[i][j])->c.z);
			if (obj.intersect[i](r, (obj.type)[i][j]) == 0)
			{
//printf("r_in = %f, %f, %f\n", r->d_w.x, r->d_w.y, r->d_w.z);
				if (r->t0 < r->tnear)
				{
					r->tnear = r->t0;
					save->i = i;
					save->j = j;
//printf("%d\n", save->j);
				}
			}
		}
	}
	if (save->i == -1)
		return (obj.bg_clr);
	r->hit_i = save->i;
	r->hit_j = save->j;
	obj.treatment[save->i]((obj.type)[save->i][save->j],
						   &color, &obj, r);
	return (color);
}

void		ft_init_ray(t_r *r)
{
	ft_init_vect(&r->o_w, 0, 0, 0);
	ft_init_vect(&r->d_w, 0, 0, 0);
	ft_init_vect(&r->p_hit, 0, 0, 0);
	ft_init_vect(&r->n_hit, 0, 0, 0);
}

int			raytracer(t_obj *obj, t_cam cam)
{
	int			i;
	int			j;
	t_r			r;
	double		**c2w;
	t_save		save;
	t_obj		new_obj;

	new_obj = *obj;
	if (!(c2w = ft_init_matrix(&cam.b.vx, &cam.b.vy, &cam.b.vz, &cam.trans)))
		return (-1);
	ft_init_ray(&r);
	//ft_mult_vect_by_matrix(&r.o, c2w, ro_c);
	r.o_w = cam.ro;//equivalent a ligne au dessus mais sans bouger la cam
	j = -1;
	while  (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			new_obj.depth = 0;
			ft_find_pixel_pos_on_screen(&cam.rp, i, j);
			ft_mult_vect_by_matrix(&r.d_w, c2w, cam.rp);
			ft_vect_difference(&r.d_w, r.d_w, r.o_w);
			ft_normalize_vect(&r.d_w);
			obj->pixel[j][i] = ft_trace(new_obj, &r, &save);
			// attention fonction au dessus, pas sur de & de 'r'
//printf("b = %d && g = %d && r = %d\n", (obj->pixel[j][i]).b, (obj->pixel[j][i]).g, (obj->pixel[j][i]).r);
		}
	}
	return (0);
}

int		key_hook(int key, t_mlx *mlx)
{
	t_mlx  plouf;

	plouf = *mlx;
	*mlx = plouf;
	if (key == 65307)
	{
		mlx = NULL;
		exit(0);
	}
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	ft_putendl_fd("FINI", 2);
	return (0);
}

int		main(int ac, char **av)
{
	t_cam		cam;
	t_mlx		mlx;

	if (ac != 2 || !av[1])
		return (ft_error("Please choose one scene", "", -1));
	ft_init_camera(&cam);
	ft_init_object_structure(&mlx.obj);
	/*	if (ft_parser(av[1], &mlx.obj) == -1)
		return (-1);*/
	ft_do_scene(&mlx.obj);//correspond a ft_parser
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "RT");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.i.data = mlx_get_data_addr(mlx.img, &(mlx.i.bpp), &(mlx.i.sl),
									&(mlx.i.endian));
	mlx_key_hook(mlx.win, key_hook, &mlx);
	raytracer(&mlx.obj, cam);
	ft_draw(&mlx);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
