/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 09:45:39 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/14 20:05:18 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

#include "libft.h"
void		ft_transform_in_unit_vect(t_v *vect)
{
	double	norm;

	norm = ft_vect_norm(*vect);
	(*vect).x = (*vect).x / norm;
	(*vect).y = (*vect).y / norm;
	(*vect).z = (*vect).z / norm;
}

void		ft_find_orthonormal_vect(t_v *vect, t_v *ortho_vect)
{
	(*ortho_vect).x = -(*vect).z / ((*vect).x + (*vect).y);
	(*ortho_vect).y = (*ortho_vect).x;
	(*ortho_vect).z = 1;
}

void		ft_find_third_orthonormal_vect(t_v *u, t_v *v, t_v *w)
{
	(*v).x = (*w).y * (*u).z - (*w).z * (*u).y;
	(*v).y = -((*w).x * (*u).z - (*w).z * (*u).x);
	(*v).z = (*w).x * (*u).y - (*w).y * (*u).x;
}

void		ft_create_orthonormal_basis(t_v *u, t_v *v, t_v *w)
{
	ft_find_orthonormal_vect(w, u);
	ft_find_third_orthonormal_vect(u, v, w);
	ft_transform_in_unit_vect(u);
	ft_transform_in_unit_vect(v);
	ft_transform_in_unit_vect(w);
}

void		ft_save_transfer_matrix(double ***mat, t_v w)
{
	t_base		base;
	t_v			u;
	t_v			v;

	ft_init_vect(&(base.v1), 1, 0, 0);
	ft_init_vect(&(base.v2), 0, 1, 0);
	ft_init_vect(&(base.v3), 0, 0, 1);
	ft_create_orthonormal_basis(&u, &v, &w);
	ft_putnbr(u.x * 100);
	ft_putchar(' ');
	ft_putnbr(u.y * 100);
	ft_putchar(' ');
	ft_putnbr(u.z * 100);
	ft_putchar('\n');
	ft_putnbr(v.x * 100);
	ft_putchar(' ');
	ft_putnbr(v.y * 100);
	ft_putchar(' ');
	ft_putnbr(v.z * 100);
	ft_putchar('\n');
	ft_putnbr(w.x * 100);
	ft_putchar(' ');
	ft_putnbr(w.y * 100);
	ft_putchar(' ');
	ft_putnbr(w.z * 100);
	ft_putchar('\n');
	(*mat)[0][0] = ft_dot_product(base.v1, u);
	(*mat)[0][1] = ft_dot_product(base.v1, v);
	(*mat)[0][2] = ft_dot_product(base.v1, w);
	(*mat)[0][3] = 0;
	(*mat)[1][0] = ft_dot_product(base.v2, u);
	(*mat)[1][1] = ft_dot_product(base.v2, v);
	(*mat)[1][2] = ft_dot_product(base.v2, w);
	(*mat)[1][3] = 0;
	(*mat)[2][0] = ft_dot_product(base.v3, u);
	(*mat)[2][1] = ft_dot_product(base.v3, v);
	(*mat)[2][2] = ft_dot_product(base.v3, w);
	(*mat)[2][3] = 0;
	(*mat)[3][0] = 0;
	(*mat)[3][1] = 0;
	(*mat)[3][2] = 0;
	(*mat)[3][3] = 1;
}

void		ft_save_transfer_matrix_inverse(double ***mat, t_v w)
{
	t_base		base;
	t_v			u;
	t_v			v;

	ft_init_vect(&(base.v1), 1, 0, 0);
	ft_init_vect(&(base.v2), 0, 1, 0);
	ft_init_vect(&(base.v3), 0, 0, 1);
	ft_create_orthonormal_basis(&u, &v, &w);
	ft_putnbr(u.x * 100);
	ft_putchar(' ');
	ft_putnbr(u.y * 100);
	ft_putchar(' ');
	ft_putnbr(u.z * 100);
	ft_putchar('\n');
	ft_putnbr(v.x * 100);
	ft_putchar(' ');
	ft_putnbr(v.y * 100);
	ft_putchar(' ');
	ft_putnbr(v.z * 100);
	ft_putchar('\n');
	ft_putnbr(w.x * 100);
	ft_putchar(' ');
	ft_putnbr(w.y * 100);
	ft_putchar(' ');
	ft_putnbr(w.z * 100);
	ft_putchar('\n');
	(*mat)[0][0] = ft_dot_product(u, base.v1);
	(*mat)[0][1] = ft_dot_product(u, base.v2);
	(*mat)[0][2] = ft_dot_product(u, base.v3);
	(*mat)[0][3] = 0;
	(*mat)[1][0] = ft_dot_product(v, base.v1);
	(*mat)[1][1] = ft_dot_product(v, base.v2);
	(*mat)[1][2] = ft_dot_product(v, base.v3);
	(*mat)[1][3] = 0;
	(*mat)[2][0] = ft_dot_product(w, base.v1);
	(*mat)[2][1] = ft_dot_product(w, base.v2);
	(*mat)[2][2] = ft_dot_product(w, base.v3);
	(*mat)[2][3] = 0;
	(*mat)[3][0] = 0;
	(*mat)[3][1] = 0;
	(*mat)[3][2] = 0;
	(*mat)[3][3] = 1;
}

t_v			ft_diff_vect(t_v vect1, t_v vect2)
{
	t_v		vect;

	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return (vect);
}

double		ft_dot_product(t_v vect1, t_v vect2)
{
	double	result;

	result = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (result);
}
