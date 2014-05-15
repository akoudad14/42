/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:40:10 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/09 19:12:56 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "philo.h"

void	ft_wait(t_sh **sh)
{
	int		type;

	type = (*(*sh)->type)[(*sh)->id];
	if (type == E)
	{
		(*(*sh)->last_eat)[(*sh)->id] = time(NULL);
		usleep((int)EAT_T * 1000000);
	}
	else if (type == T)
		usleep((int)THINK_T * 1000000);
	else if (type == R)
		usleep((int)REST_T * 1000000);
}

void	*ft_go(void *data)
{
	t_sh		*sh;
	int			s_l;
	int			s_r;

	sh = (t_sh *)data;
	s_l = sh->id;
	s_r = sh->id == 0 ? 6 : sh->id - 1;
	while (1)
	{
		pthread_mutex_lock(sh->mut);
		if (*sh->dead == -1)
			break ;
		if ((*sh->type)[sh->id] == E)
			ft_was_eating(&sh, s_l, s_r);
		else if ((*sh->type)[sh->id] == T)
			ft_was_thinking(&sh, s_l, s_r);
		else if ((*sh->type)[sh->id] == R)
			ft_was_resting(&sh, s_l, s_r);
		else
			ft_was_waiting(&sh, s_l, s_r);
		pthread_mutex_unlock(sh->mut);
		ft_wait(&sh);
	}
	pthread_mutex_unlock(sh->mut);
	return (NULL);
}

void	*ft_represent(void *data)
{
	t_sh	*sh;
	int		ret;

	sh = (t_sh *)data;
	ret = 0;
	while (ret == 0)
	{
		pthread_mutex_lock(sh->mut);
		ft_draw(&sh, &ret);
		pthread_mutex_unlock(sh->mut);
		if (ret == -1)
			break ;
		usleep(100000);
	}
	return (NULL);
}

int		ft_philo(t_mlx *mlx)
{
	int				i;
	t_sh			*sh;
	t_sh2			*sh2;
	pthread_t		*tab;

	if (ft_init0(&sh, &sh2, mlx, &tab) == -1 || ft_init1(&sh, &sh2) == -1
		|| ft_init2(&sh, &sh2) == -1 || ft_init3(&sh, &sh2) == -1)
		return (-1);
	i = -1;
	while (++i < NB_PHILO)
		pthread_create(&tab[i], NULL, ft_go, &sh[i]);
	pthread_create(&tab[i], NULL, ft_represent, &sh[i]);
	i = -1;
	while (++i < (NB_PHILO + 1))
		pthread_join(tab[i], NULL);
	return (0);
}

int		main(void)
{
	t_mlx		mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "LES 7 PHILOSOPHES");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.i.data = mlx_get_data_addr(mlx.img, &(mlx.i.bpp), &(mlx.i.sl),
									&(mlx.i.endian));
	mlx_key_hook(mlx.win, key_hook, &mlx);
	ft_philo(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
