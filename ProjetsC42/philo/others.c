/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:39:18 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/09 19:15:37 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "libft.h"

int		ft_finish(t_sh **sh, char *finish)
{
	*(*sh)->dead = -1;
	if (finish[0] != '\0')
		ft_putendl(finish);
	return (-1);
}

int		key_hook(int key, t_mlx *mlx)
{
	t_mlx	*tmp;

	tmp = mlx;
	mlx = tmp;
	if (key == 65307)
	{
		mlx = NULL;
		cfree();
		exit(0);
	}
	return (0);
}

void	ft_place_philo2(int id, int *i, int *j)
{
	if (id == 3)
	{
		*i = 650;
		*j = 250;
	}
	else if (id == 4)
	{
		*i = 500;
		*j = 400;
	}
	else if (id == 5)
	{
		*i = 300;
		*j = 400;
	}
	else if (id == 6)
	{
		*i = 100;
		*j = 330;
	}
}

void	ft_place_philo(int id, int *i, int *j)
{
	if (id == 0)
	{
		*i = 100;
		*j = 170;
	}
	else if (id == 1)
	{
		*i = 300;
		*j = 100;
	}
	else if (id == 2)
	{
		*i = 500;
		*j = 100;
	}
	else
		ft_place_philo2(id, i, j);
}
