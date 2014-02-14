/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:57:11 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/14 20:53:09 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rtv1.h"

#include "libft.h"
#include <stdio.h>
t_v			ft_transform_in_new_basis(t_v start, double **mat)
{
	t_v		new;

	new.x = start.x * mat[0][0] + start.y * mat[0][1]
			+ start.z * mat[0][2];
	new.y = start.x * mat[1][0] + start.y * mat[1][1]
			+ start.z * mat[1][2];
	new.z = start.x * mat[2][0] + start.y * mat[2][1]
			+ start.z * mat[2][2];
	return (new);
}

double		ft_is_in_cylinder_2(t_cyl cyl, t_v start, t_v dir)
{
	double		a;
	double		b;
	double		c;
	double		sol;

	a = pow(dir.x, 2) + pow(dir.y, 2);
	b = 2 * (start.x * dir.x + start.y + dir.y);
	c = pow(start.x, 2) + pow(start.y, 2) - pow(cyl.r, 2);
	sol = ft_nearest_solution(a, b, c);
	return (sol);

}

double		ft_is_in_cylinder(t_cam cam, t_cyl cyl, t_v start)
{
	t_v			dir;
	double		sol;

	dir = ft_transform_in_new_basis(cam.d, cyl.mat);
	printf("dir = x.%f y.%f z.%f\n", dir.x, dir.y, dir.z);
	sol = ft_is_in_cylinder_2(cyl, start, dir);
	return (sol);
}

double		ft_find_nearest_cylinder(int *ind, t_cam cam, t_cyll *cyll)
{
	t_cyll		*move;
	int			i;
	double		dist;
	double		min;
	t_v			start;
	t_v			tmp_neg;

	i = 0;
	move = cyll;
	if (!move)
		return (-1);
	start = ft_diff_vect(cam.e, move->cyl.c);
	start = ft_transform_in_new_basis(start, move->cyl.mat);
	ft_init_vect(&(tmp_neg), -move->cyl.c.x, -move->cyl.c.y, -move->cyl.c.z);
	start = ft_diff_vect(start, tmp_neg);
	printf("start = x.%f y.%f z.%f\n", start.x, start.y, start.z);
	min = ft_is_in_cylinder(cam, move->cyl, start);
	*ind = i;
	++i;
	while ((move = move->next))
	{
		dist = ft_is_in_cylinder(cam, move->cyl, start);
		if (dist != -1 && (min == -1 || min > dist))
		{
			min = dist;
			*ind = i;
		}
		++i;
	}
	return (min);
}
