/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:23:46 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/27 11:38:37 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double		ft_hit_or_not(t_r *r, t_obj *obj)
{
	int		i;
	int		j;
	t_save	save;

	ft_init_save_and_ray(r, &save);
	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj.nb[i])
		{
			if (obj.intersect[i](r, (obj.type)[i][j]) == 0)
			{
				if (r->t0 < r->tnear)
				{
					r->tnear = r->t0;
					save->i = 
		}
}

double				ft_hit_light(t_r *r, t_obj *obj)
{
	int		i;
	t_r		r_l;
	t_sph	*light;

	i = 0;
	light = NULL;
	while (i < obj.nb[SPH] && (((t_sph ***)obj.type)[SPH][i])->em.x == 0
		   && (((t_sph ***)obj.type)[SPH][i])->em.y == 0
		   && (((t_sph ***)obj.type)[SPH][i])->em.z == 0)
		++i;
	if (i == obj.nb[SPH])
		return (2.0);
	light = ((t_sph ***)obj.type)[SPH][i];
	ft_init_vect(r_l.o_w, light->c.x, light->c.y, light->c.z);
	r_l.d_w = ft_vect_diff(r->p_hit, r_l.o_w);
	r_l.hit_i = r->hit_i;
	r_l.hit_j = r->hit_j;
	return (ft_hit_or_not(&r_l, obj));
}
