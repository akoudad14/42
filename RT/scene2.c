/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 16:26:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:58:08 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

int		ft_init_object_structure(t_obj *obj)
{
	int		i;

	if (!(obj->pixel = (t_c **)gmalloc(sizeof(t_c *) * HEIGHT))
		|| !(obj->type = (void ***)gmalloc(sizeof(void **) * NB_TYPE))
		|| !(obj->nb = (int *)gmalloc(sizeof(int) * NB_TYPE)))
		return (-1);
	i = -1;
	while (++i < HEIGHT)
	{
		if (!(obj->pixel[i] = (t_c *)gmalloc(sizeof(t_c) * WIDTH)))
			return (-1);
	}
	i = -1;
	while (++i < NB_TYPE)
		obj->nb[i] = 0;
	obj->intersect[0] = ft_intersect_a_box;
	obj->intersect[1] = ft_intersect_a_sphere;
	obj->intersect[2] = ft_intersect_a_plane;
	obj->intersect[3] = ft_intersect_a_disk;
	obj->treatment[0] = ft_treat_a_box;
	obj->treatment[1] = ft_treat_a_sphere;
	obj->treatment[2] = ft_treat_a_plane;
	obj->treatment[3] = ft_treat_a_disk;
	ft_init_color(&(obj->bg_clr), 0, 0, 0);
	return (0);
}


#include <stdio.h>



int		ft_do_scene(t_obj *obj)
{
	t_sph	**lsph;
	t_pla	**lpla;
	t_dis	**ldis;
	int		i;

	obj->nb[SPH] = 20;
	if (!(((t_sph ***)obj->type)[SPH]
		  = (t_sph **)gmalloc(sizeof(t_sph *) * obj->nb[SPH])))
		return (-1);
	lsph = ((t_sph ***)obj->type)[SPH];
	i = -1;
	while (++i < obj->nb[SPH])
	{
		if (!(lsph[i] = (t_sph *)gmalloc(sizeof(t_sph))))
			return (-1);
	}	
	ft_init_vect(&lsph[0]->c, -3, 0, -1500);
	lsph[0]->r = 0.0001;
	ft_init_color(&lsph[0]->sf, 255, 255, 255);
	ft_init_color(&lsph[0]->em, 255, 255, 255);
	
	ft_init_vect(&lsph[1]->c, 0, 2, -3980);
	lsph[1]->r = 0.1;
	ft_init_color(&lsph[1]->sf, 120, 120, 120);
	ft_init_color(&lsph[1]->em, 0, 0, 0);
	
	ft_init_vect(&lsph[2]->c, 0, -2, -3980);
	lsph[2]->r = 1;
	ft_init_color(&lsph[2]->sf, 20, 70, 0);
	ft_init_color(&lsph[2]->em, 0, 0, 0);

	ft_init_vect(&lsph[3]->c, 5, 2, -3980);
	lsph[3]->r = 0.7;
	ft_init_color(&lsph[3]->sf, 120, 0, 0);
	ft_init_color(&lsph[3]->em, 0, 0, 0);

	ft_init_vect(&lsph[4]->c, 7, -6, -2000);//rouge
	lsph[4]->r = 2;
	ft_init_color(&lsph[4]->sf, 20, 10, 80);
	ft_init_color(&lsph[4]->em, 0, 0, 0);
	
	ft_init_vect(&lsph[5]->c, 0, -7, -2005);
	lsph[5]->r = 1.2;
	ft_init_color(&lsph[5]->sf, 50, 50, 0);
	ft_init_color(&lsph[5]->em, 0, 0, 0);
	
	ft_init_vect(&lsph[6]->c, 8.5, -7.5, -1997);
	lsph[6]->r = 0.7;
	ft_init_color(&lsph[6]->sf, 0, 80, 80);
	ft_init_color(&lsph[6]->em, 0, 0, 0);

	ft_init_vect(&lsph[7]->c, 5.8, -5.7, -1998.35);//rouge
	lsph[7]->r = 0.2;
	ft_init_color(&lsph[7]->sf, 10, 10, 30);
	ft_init_color(&lsph[7]->em, 0, 0, 0);
	
	ft_init_vect(&lsph[8]->c, 7, -5.7, -1998);
	lsph[8]->r = 0.2;
	ft_init_color(&lsph[8]->sf, 10, 10, 30);
	ft_init_color(&lsph[8]->em, 0, 0, 0);

	ft_init_vect(&lsph[9]->c, 6, -2, -3980);
	lsph[9]->r = 0.05;
	ft_init_color(&lsph[9]->sf, 120, 120, 120);
	ft_init_color(&lsph[9]->em, 0, 0, 0);

	ft_init_vect(&lsph[10]->c, 0, -5.5, -3980);
	lsph[10]->r = 0.05;
	ft_init_color(&lsph[10]->sf, 120, 120, 120);
	ft_init_color(&lsph[10]->em, 0, 0, 0);
	
	ft_init_vect(&lsph[11]->c, 2, -6, -3980);
	lsph[11]->r = 0.08;
	ft_init_color(&lsph[11]->sf, 120, 120, 120);
	ft_init_color(&lsph[11]->em, 0, 0, 0);

	ft_init_vect(&lsph[12]->c, 8, 1, -3980);
	lsph[12]->r = 0.07;
	ft_init_color(&lsph[12]->sf, 120, 120, 120);
	ft_init_color(&lsph[12]->em, 0, 0, 0);

	ft_init_vect(&lsph[13]->c, 0.1, -6.8, -2003.4);
	lsph[13]->r = 0.15;
	ft_init_color(&lsph[13]->sf, 20, 20, 0);
	ft_init_color(&lsph[13]->em, 0, 0, 0);

	ft_init_vect(&lsph[14]->c, 0.7, -6.8, -2004);
	lsph[14]->r = 0.15;
	ft_init_color(&lsph[14]->sf, 20, 20, 0);
	ft_init_color(&lsph[14]->em, 0, 0, 0);

	ft_init_vect(&lsph[15]->c, -3, -1.8, -599);
	lsph[15]->r = 0.02;
	ft_init_color(&lsph[15]->sf, 120, 120, 120);
	ft_init_color(&lsph[15]->em, 0, 0, 0);
	
	ft_init_vect(&lsph[16]->c, -3.1, -0.8, -598);
	lsph[16]->r = 0.013;
	ft_init_color(&lsph[16]->sf, 120, 120, 120);
	ft_init_color(&lsph[16]->em, 0, 0, 0);

	ft_init_vect(&lsph[17]->c, -2.9, 2, -599);
	lsph[17]->r = 0.016;
	ft_init_color(&lsph[17]->sf, 120, 120, 120);
	ft_init_color(&lsph[17]->em, 0, 0, 0);

	ft_init_vect(&lsph[18]->c, -2.9, 0.7, -599);
	lsph[18]->r = 0.025;
	ft_init_color(&lsph[18]->sf, 120, 120, 120);
	ft_init_color(&lsph[18]->em, 0, 0, 0);

	ft_init_vect(&lsph[19]->c, -3, 0.5, -598);
	lsph[19]->r = 0.25;
	ft_init_color(&lsph[19]->sf, 0, 50, 120);
	ft_init_color(&lsph[19]->em, 0, 0, 0);

	obj->nb[PLA] = 5;
	if (!(((t_pla ***)obj->type)[PLA]
		  = (t_pla **)gmalloc(sizeof(t_pla *) * obj->nb[PLA])))
		return (-1);
	lpla = ((t_pla ***)obj->type)[PLA];
	i = -1;
	while (++i < obj->nb[PLA])
	{
		if (!(lpla[i] = (t_pla *)gmalloc(sizeof(t_pla))))
			return (-1);
	}
	ft_init_vect(&lpla[0]->c, 0, 0, -4000);
	ft_init_vect(&lpla[0]->n, 0, 0, 1);
	ft_normalize_vect(&lpla[0]->n);
	ft_init_color(&lpla[0]->sf, 25, 25, 25);

	ft_init_vect(&lpla[1]->c, 0, 7, -2000);
	ft_init_vect(&lpla[1]->n, 0, -1, 0);
	ft_normalize_vect(&lpla[1]->n);
	ft_init_color(&lpla[1]->sf, 60, 60, 60);
	
	ft_init_vect(&lpla[2]->c, 0, -9, -2000);
	ft_init_vect(&lpla[2]->n, 0, 1, 0);
	ft_normalize_vect(&lpla[2]->n);
	ft_init_color(&lpla[2]->sf, 60, 60, 60);
	
	ft_init_vect(&lpla[3]->c, -4, 0, -2000);
	ft_init_vect(&lpla[3]->n, 1, 0, 0);
	ft_normalize_vect(&lpla[3]->n);
	ft_init_color(&lpla[3]->sf, 70, 70, 70);
	
	ft_init_vect(&lpla[4]->c, 12, 0, -2000);
	ft_init_vect(&lpla[4]->n, -1, 0, 0);
	ft_normalize_vect(&lpla[4]->n);
	ft_init_color(&lpla[4]->sf, 70, 70, 70);


	obj->nb[DIS] = 11;
	if (!(((t_dis ***)obj->type)[DIS]
		  = (t_dis **)gmalloc(sizeof(t_dis *) * obj->nb[DIS])))
		return (-1);
	ldis = ((t_dis ***)obj->type)[DIS];
	i = -1;
	while (++i < obj->nb[DIS])
	{
		if (!(ldis[i] = (t_dis *)gmalloc(sizeof(t_dis))))
			return (-1);
	}
	ft_init_vect(&ldis[0]->c, 4, -1, -3990);
	ldis[0]->r = 7;
	ft_init_vect(&ldis[0]->n, 0, 0, -1);
	ft_normalize_vect(&ldis[0]->n);
	ft_init_color(&ldis[0]->sf, 10, 10, 10);

	ft_init_vect(&ldis[1]->c, -4.95, 0, -1000);
	ldis[1]->r = 3;
	ft_init_vect(&ldis[1]->n, 1, 0, 0);
	ft_normalize_vect(&ldis[1]->n);
	ft_init_color(&ldis[1]->sf, 0, 0, 0);
	
	ft_init_vect(&ldis[2]->c, 5, 2, -3980);
	ldis[2]->r = 1;
	ft_init_vect(&ldis[2]->n, 0.5, 1, 0.5);
	ft_normalize_vect(&ldis[2]->n);
	ft_init_color(&ldis[2]->sf, 80, 0, 0);

	ft_init_vect(&ldis[3]->c, 0, -2, -3980);
	ldis[3]->r = 1.4;
	ft_init_vect(&ldis[3]->n, -1, 0.3, 0.3);
	ft_normalize_vect(&ldis[3]->n);
	ft_init_color(&ldis[3]->sf, 10, 50, 0);

	ft_init_vect(&ldis[4]->c, 7, -5, -2000);
	ldis[4]->r = 2;
	ft_init_vect(&ldis[4]->n, 1, 0, 0.3);
	ft_normalize_vect(&ldis[4]->n);
	ft_init_color(&ldis[4]->sf, 20, 10, 50);

	ft_init_vect(&ldis[5]->c, 0, -6.2, -2005);
	ldis[5]->r = 1;
	ft_init_vect(&ldis[5]->n, -1, 0, 0.4);
	ft_normalize_vect(&ldis[5]->n);
	ft_init_color(&ldis[5]->sf, 30, 30, 0);
	
	ft_init_vect(&ldis[6]->c, 8.5, -7, -1997);
	ldis[6]->r = 0.7;
	ft_init_vect(&ldis[6]->n, 1, 0, 0.3);
	ft_normalize_vect(&ldis[6]->n);
	ft_init_color(&ldis[6]->sf, 0, 50, 50);

	ft_init_vect(&ldis[7]->c, 6.6, -6.6, -1998.5);
	ldis[7]->r = 0.9;
	ft_init_vect(&ldis[7]->n, -0.1, 1, 0.5);
	ft_normalize_vect(&ldis[7]->n);
	ft_init_color(&ldis[7]->sf, 20, 10, 50);

	ft_init_vect(&ldis[8]->c, 0.4, -7.5, -2004.2);
	ldis[8]->r = 0.6;
	ft_init_vect(&ldis[8]->n, -0.2, 1, -0.5);
	ft_normalize_vect(&ldis[8]->n);
	ft_init_color(&ldis[8]->sf, 30, 30, 0);

	ft_init_vect(&ldis[9]->c, -3, 0, -600);
	ldis[9]->r = 3;
	ft_init_vect(&ldis[9]->n, 1, 0, 0.2);
	ft_normalize_vect(&ldis[9]->n);
	ft_init_color(&ldis[9]->sf, 0, 0, 0);

	ft_init_vect(&ldis[3]->c, -3, 0.5, -598);
	ldis[3]->r = 0.32;
	ft_init_vect(&ldis[3]->n, 0.2, 1, 0.3);
	ft_normalize_vect(&ldis[3]->n);
	ft_init_color(&ldis[3]->sf, 0, 20, 80);
	return (0);
}
