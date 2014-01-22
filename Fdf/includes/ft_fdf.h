/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:41:49 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 19:39:53 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_FDF_H
# define	FT_FDF_H

# define	A	1
# define	C	20
# define	K	20
# define	O	500

typedef struct		s_fdf
{
	char			*line;
	struct s_fdf	*next;
}					t_fdf;

typedef struct		s_draw
{
	int				nb_line;
	int				nb_col;
	int				**tab;
	void			*mlx_ptr;
	void			*win;
	double			a;
	int				c;
	int				k;
	int				x;
	int				y;
	long			c1;
	long			c2;
	double			s;
}					t_draw;

typedef struct		s_coor
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_coor;

void		ft_draw_grid(int nb_line, int nb_col, int **tab);
void		ft_coor_ver(t_draw e, int **tab, int i, int j);
void		ft_coor_hor(t_draw e, int **tab, int i, int j);
int			ft_count_wd(char *str, char c);
void		ft_key_color(int keycode, t_draw *e);

#endif	/* !FT_FDF_H */
