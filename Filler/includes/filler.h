/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 10:41:49 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/18 14:41:29 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FILLER_H
# define	FILLER_H

# include	<stdio.h>
# include	"libft.h"

typedef struct		s_p
{
	char			**piece;
	int				xp;
	int				yp;
	int				rxp;
	int				ryp;
}					t_p;

typedef struct		s_m
{
	char			**map;
	int				xm;
	int				ym;
	char			c;
}					t_m;

typedef struct		s_c
{
	int				xm;
	int				ym;
	int				xp;
	int				yp;
	int				check;
}					t_c;

int			ft_map(char *p, t_m *m, t_p *piece);
int			ft_place_piece(t_m *m, t_p *p);
int			ft_perror(char *str);

#endif	/* !FILLER_H */
