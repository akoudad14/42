/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:36:41 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/09 19:00:57 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "philo.h"
#include "libft.h"

void	ft_give_color(t_sh **sh)
{
	int		color;
	int		k;

	color = 0;
	k = -1;
	while (++k < NB_PHILO)
	{
		if ((*(*sh)->type)[k] == E)
			color = 0;
		else if ((*(*sh)->type)[k] == T)
			color = 1;
		else if ((*(*sh)->type)[k] == R)
			color = 2;
		else
			color = -1;
		ft_place_philo(k, &(*sh)->i, &(*sh)->j);
		ft_draw_one_philo((*sh)->mlx, color, (*sh)->i, (*sh)->j);
	}
}

void	ft_string_put(t_sh **sh, int i, int j, int k)
{
	if ((*(*sh)->type)[k] == E)
		mlx_string_put((*sh)->mlx->mlx, (*sh)->mlx->win, i, j + 45,
						0xFFFFFF, "EAT");
	else if ((*(*sh)->type)[k] == T)
		mlx_string_put((*sh)->mlx->mlx, (*sh)->mlx->win, i, j + 45,
						0xFFFFFF, "THINK");
	else if ((*(*sh)->type)[k] == R)
		mlx_string_put((*sh)->mlx->mlx, (*sh)->mlx->win, i, j + 45,
						0xFFFFFF, "REST");
	else
		mlx_string_put((*sh)->mlx->mlx, (*sh)->mlx->win, i, j + 45,
						0xFFFFFF, "WAIT");
}

void	ft_new_life(t_sh **sh, int *life, int now, int k)
{
	if ((*(*sh)->last_eat)[k] > (*(*sh)->life)[k]
		|| ((*(*sh)->last_eat)[k] == (*(*sh)->life)[k]
			&& (*(*sh)->type)[k] == E))
		*life = MAX_LIFE - ((*(*sh)->last_eat)[k] - (*(*sh)->life)[k]);
	else
		*life = (*(*sh)->life)[k] - now + MAX_LIFE;
}

void	ft_draw(t_sh **sh, int *dead)
{
	int		k;
	int		now;
	char	*str;
	int		life;

	now = time(NULL);
	if (now - (*(*sh)->life)[7] > TIMEOUT)
		*dead = ft_finish(sh, "Now, it is time... To DAAAAAAAANCE ! ! !");
	ft_give_color(sh);
	mlx_put_image_to_window((*sh)->mlx->mlx, (*sh)->mlx->win,
		(*sh)->mlx->img, 0, 0);
	k = -1;
	while (++k < NB_PHILO)
	{
		ft_place_philo(k, &(*sh)->i, &(*sh)->j);
		ft_new_life(sh, &life, now, k);
		str = ft_itoa(life);
		if (life <= 0)
			*dead = ft_finish(sh, "");
		mlx_string_put((*sh)->mlx->mlx, (*sh)->mlx->win, (*sh)->i + 3,
						(*sh)->j - 15, 0xFFFFFF, str);
		ft_string_put(sh, (*sh)->i, (*sh)->j, k);
	}
}

int		ft_draw_one_philo(t_mlx *mlx, int color, int begin_i, int begin_j)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 20)
	{
		i = -1;
		while (++i < 20)
		{
			mlx->i.data[0 + (i + begin_i) * 4 + (j + begin_j) * mlx->i.sl] = 0;
			mlx->i.data[1 + (i + begin_i) * 4 + (j + begin_j) * mlx->i.sl] = 0;
			mlx->i.data[2 + (i + begin_i) * 4 + (j + begin_j) * mlx->i.sl] = 0;
			if (color == -1)
			{
				mlx->i.data[0 + (i + begin_i) * 4
							+ (j + begin_j) * mlx->i.sl] = 255;
				mlx->i.data[1 + (i + begin_i) * 4
							+ (j + begin_j) * mlx->i.sl] = 255;
			}
			else
				mlx->i.data[color + (i + begin_i) * 4
							+ (j + begin_j) * mlx->i.sl] = 255;
		}
	}
	return (0);
}
