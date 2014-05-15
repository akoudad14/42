/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:36:57 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/09 18:37:49 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

int		ft_init0(t_sh **sh, t_sh2 **sh2, t_mlx *mlx, pthread_t **tab)
{
	int		i;

	if (!(*sh = (t_sh *)gmalloc(sizeof(t_sh) * (NB_PHILO + 1)))
		|| !(*sh2 = (t_sh2 *)gmalloc(sizeof(t_sh2) * (NB_PHILO + 1)))
		|| !(*tab = (pthread_t *)gmalloc(sizeof(pthread_t) * (NB_PHILO + 1))))
		return (-1);
	i = -1;
	while (++i < (NB_PHILO + 1))
	{
		(*sh)[i].id = i;
	}
	(*sh)[i - 1].mlx = mlx;
	return (0);
}

int		ft_init1(t_sh **sh, t_sh2 **sh2)
{
	int		i;

	if (!((*sh2)->stick = (int *)gmalloc(sizeof(int) * NB_PHILO)))
		return (-1);
	pthread_mutex_init(&(*sh2)->mut, NULL);
	i = -1;
	while (++i < NB_PHILO)
	{
		(*sh2)->stick[i] = -1;
	}
	i = -1;
	while (++i < (NB_PHILO + 1))
	{
		(*sh)[i].stick = &(*sh2)->stick;
		(*sh)[i].mut = &(*sh2)->mut;
	}
	return (0);
}

int		ft_init2(t_sh **sh, t_sh2 **sh2)
{
	int		i;

	(*sh2)->dead = 0;
	if (!((*sh2)->type = (int *)gmalloc(sizeof(int) * NB_PHILO)))
		return (-1);
	i = -1;
	while (++i < NB_PHILO)
		(*sh2)->type[i] = R;
	i = -1;
	while (++i < (NB_PHILO + 1))
	{
		(*sh)[i].type = &(*sh2)->type;
		(*sh)[i].dead = &(*sh2)->dead;
	}
	return (0);
}

int		ft_init3(t_sh **sh, t_sh2 **sh2)
{
	int			i;

	if (!((*sh2)->last_eat = (int *)gmalloc(sizeof(int) * NB_PHILO))
		|| !((*sh2)->life = (time_t *)gmalloc(sizeof(time_t) * (NB_PHILO + 1))))
		return (-1);
	(*sh2)->life[0] = time(NULL);
	i = -1;
	while (++i < NB_PHILO)
	{
		(*sh2)->life[i] = (*sh2)->life[0];
		(*sh2)->last_eat[i] = (*sh2)->life[0];
	}
	(*sh2)->life[i] = (*sh2)->life[0];
	i = -1;
	while (++i < (NB_PHILO + 1))
	{
		(*sh)[i].life = &(*sh2)->life;
		(*sh)[i].last_eat = &(*sh2)->last_eat;
	}
	return (0);
}
