/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 19:23:52 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/09 19:23:53 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PHILO_H
# define	PHILO_H

# define	NB_PHILO	7
# define	MAX_LIFE	16
# define	EAT_T		4
# define	REST_T		6
# define	THINK_T		5
# define	TIMEOUT		40
# define	E			0
# define	R			1
# define	T			2
# define	W			3
# define	HEIGHT		(550.0)
# define	WIDTH		(800.0)

# include <pthread.h>

typedef struct			s_img
{
	char				*data;
	int					bpp;
	int					sl;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	t_img				i;
}						t_mlx;

typedef struct			s_sh2
{
	int					*stick;
	pthread_mutex_t		mut;
	time_t				*life;
	int					*type;
	t_mlx				mlx;
	int					dead;
	int					*last_eat;
}						t_sh2;

typedef struct			s_sh
{
	int					id;
	int					**stick;
	pthread_mutex_t		*mut;
	time_t				**life;
	int					**type;
	t_mlx				*mlx;
	int					*dead;
	int					**last_eat;
	int					i;
	int					j;
}						t_sh;

/*
**	main.c
*/
void					ft_wait(t_sh **sh);
void					*ft_go(void *data);
void					*ft_represent(void *data);
int						ft_philo(t_mlx *mlx);

/*
**	init.c
*/
int						ft_init0(t_sh **sh, t_sh2 **sh2,
								t_mlx *mlx, pthread_t **tab);
int						ft_init1(t_sh **sh, t_sh2 **sh2);
int						ft_init2(t_sh **sh, t_sh2 **sh2);
int						ft_init3(t_sh **sh, t_sh2 **sh2);

/*
**	last_type.c
*/
void					ft_was_eating(t_sh **sh, int s_l, int s_r);
void					ft_was_thinking(t_sh **sh, int s_l, int s_r);
void					ft_was_resting(t_sh **sh, int s_l, int s_r);
void					ft_was_waiting2(t_sh **sh, int s_l, int s_r);
void					ft_was_waiting(t_sh **sh, int s_l, int s_r);

/*
**	draw.c
*/
void					ft_give_color(t_sh **sh);
void					ft_string_put(t_sh **sh, int i, int j, int k);
void					ft_new_life(t_sh **sh, int *life, int now, int k);
void					ft_draw(t_sh **sh, int *dead);
int						ft_draw_one_philo(t_mlx *mlx, int color,
											int begin_i, int begin_j);

/*
**	others.c
*/
int						ft_finish(t_sh **sh, char *finish);
int						key_hook(int key, t_mlx *mlx);
void					ft_place_philo2(int id, int *i, int *j);
void					ft_place_philo(int id, int *i, int *j);

#endif
