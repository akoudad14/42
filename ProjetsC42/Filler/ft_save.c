/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 15:19:44 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 09:58:22 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_free_char2(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		free((void *)s[i]);
		++i;
	}
	free((void *)s);
}

static int		ft_piece(t_m *m, t_p *piece)
{
	char	**pi;
	char	*p;
	int		i;

	i = 0;
	get_next_line(0, &p);
	if (!(pi = ft_strsplit(p, ' ')))
		return (ft_perror("pi "));
	piece->xp = ft_atoi(pi[1]);
	pi[2] = ft_strsub(pi[2], 0, ft_strlen(pi[2]) - 1);
	piece->yp = ft_atoi(pi[2]);
	free((void *)p);
	ft_free_char2(pi);
	if (!(piece->piece = (char **)malloc(sizeof(char *) * (piece->xp + 1))))
		return (ft_perror("pi "));
	while (i < piece->xp)
	{
		get_next_line(0, &p);
		piece->piece[i] = ft_strdup(p);
		free((void *)p);
		++i;
	}
	piece->piece[i] = '\0';
	return (ft_place_piece(m, piece));
}

int				ft_map(char *p, t_m *m, t_p *piece)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = ft_strsplit(p, ' ')))
		return (ft_perror("map "));
	m->xm = ft_atoi(map[1]);
	map[2] = ft_strsub(map[2], 0, ft_strlen(map[2]) - 1);
	m->ym = ft_atoi(map[2]);
	free((void *)p);
	ft_free_char2(map);
	get_next_line(0, &p);
	free((void *)p);
	if (!(m->map = (char **)malloc(sizeof(char *) * (m->xm + 1))))
		return (ft_perror("map "));
	while (i < m->xm)
	{
		get_next_line(0, &p);
		m->map[i] = ft_strdup(p + 4);
		++i;
		free((void *)p);
	}
	m->map[i] = '\0';
	return (ft_piece(m, piece));
}
