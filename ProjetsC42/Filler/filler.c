/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 10:44:44 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/21 11:30:09 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_perror(char *str)
{
	perror(str);
	return (-1);
}

static void		free_char2_p(t_m *m, t_p *p)
{
	int		i;

	i = 0;
	while (i < p->xp)
	{
		free((void *)p->piece[i]);
		i++;
	}
	free((void *)p->piece);
	i = 0;
	while (i < m->xm)
	{
		free((void *)m->map[i]);
		i++;
	}
	free((void *)m->map);
}

static int		ft_play(char c)
{
	t_m		*map;
	t_p		*piece;
	char	*p;

	if (!(map = (t_m *)malloc(sizeof(*map))))
		return (ft_perror("map "));
	if (!(piece = (t_p *)malloc(sizeof(*piece))))
		return (ft_perror("piece "));
	map->c = c;
	while (get_next_line(0, &p) && ft_strncmp(p, "==", 2) != 0)
	{
		if (ft_map(p, map, piece) == -1)
		{
			free_char2_p(map, piece);
			free((void *)piece);
			free((void *)map);
			return (-1);
		}
		free_char2_p(map, piece);
	}
	free((void *)piece);
	free((void *)map);
	return (0);
}

static char		ft_player(void)
{
	char	*p;

	get_next_line(0, &p);
	while (ft_strncmp("$$$", p, 3) != 0)
	{
		free((void *)p);
		get_next_line(0, &p);
	}
	if (ft_strncmp("$$$ exec p1", p, 11) == 0)
	{
		free((void *)p);
		return ('o');
	}
	else
	{
		free((void *)p);
		return ('x');
	}
}

int				main(void)
{
	char		c;

	c = ft_player();
	if (ft_play(c) == -1)
		return (-1);
	return (0);
}
