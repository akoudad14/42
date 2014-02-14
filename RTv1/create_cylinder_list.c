/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:54:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/14 20:19:45 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "libft.h"

t_cyll		*ft_create_cylinder_elem(t_cyl cyl)
{
	t_cyll	*new;
	int		i;

	if (!(new = (t_cyll *)gmalloc(sizeof(*new))))
		return (NULL);
	ft_init_vect(&(new->cyl.c), cyl.c.x, cyl.c.y, cyl.c.z);
	ft_init_vect(&(new->cyl.a), cyl.a.x, cyl.a.y, cyl.a.z);
	new->cyl.r = cyl.r;
	ft_putnbr(new->cyl.r);
	ft_putchar('\n');
	new->cyl.ind = cyl.ind;
	new->cyl.clr.b = cyl.clr.b;
	new->cyl.clr.g = cyl.clr.g;
	new->cyl.clr.r = cyl.clr.r;
	if (!(new->cyl.mat = (double **)gmalloc(sizeof(double *) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		if (!(new->cyl.mat[i] = (double *)gmalloc(sizeof(double) * 1)))
			return (NULL);
	}
	ft_putnbr(cyl.a.x);
	ft_putnbr(cyl.a.y);
	ft_putnbr(cyl.a.z);
	ft_putchar('\n');
	ft_save_transfer_matrix_inverse(&(new->cyl.mat), cyl.a);
/*	ft_save_transfer_matrix(&(new->cyl.mat), cyl.a);*/
	ft_putnbr((new->cyl.mat)[0][0] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[0][1] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[0][2] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[0][3] * 100);
	ft_putchar('\n');
	ft_putnbr(new->cyl.mat[1][0] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[1][1] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[1][2] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[1][3] * 100);
	ft_putchar('\n');
	ft_putnbr(new->cyl.mat[2][0] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[2][1] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[2][2] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[2][3] * 100);
	ft_putchar('\n');
	ft_putnbr(new->cyl.mat[3][0] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[3][1] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[3][2] * 100);
	ft_putchar(' ');
	ft_putnbr(new->cyl.mat[3][3] * 100);
	ft_putchar('\n');
	new->next = NULL;
	return (new);
}

void		ft_fill_cylinder_info(t_cyl *c, int fd)
{
	char	*line;
	char	**save;

	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(c->c), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_free_char2(save);
	gfree((void *)line);
	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(c->a), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_free_char2(save);
	gfree((void *)line);
	get_next_line(fd, &line);
	c->r = ft_atoi(line);
	gfree((void *)line);
	get_next_line(fd, &line);
	c->ind = ft_atoi(line);
	gfree((void *)line);
	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	c->clr.b = ft_atoi(save[0]);
	c->clr.g = ft_atoi(save[1]);
	c->clr.r = ft_atoi(save[2]);
	ft_free_char2(save);
	gfree((void *)line);
}

int			ft_save_cylinder_in_list(t_cyll **cyll, int fd)
{
	t_cyl		cyl;
	t_cyll		*new_elem;

	ft_fill_cylinder_info(&cyl, fd);
	if (!(new_elem = ft_create_cylinder_elem(cyl)))
		return (-1);
	if (*cyll)
		new_elem->next = *cyll;
	*cyll = new_elem;
	return (0);
}
