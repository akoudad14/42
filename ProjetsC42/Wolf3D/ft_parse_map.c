/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:11:47 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/07 16:33:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_wolf3d.h"
#include "libft.h"

static int		ft_count_lines(char *str)
{
	int		i;
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY, S_IRUSR | S_IWUSR | S_IXUSR)) == -1)
		exit(-1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		free((void *)line);
		++i;
	}
	free((void *)line);
	close(fd);
	return (i);
}

static t_w		ft_fill_tab(t_w w, char **tmp, int j)
{
	int		i;

	i = 0;
	while (i < w.m.col)
	{
		w.m.tab[j][i] = ft_atoi(tmp[i]);
		++i;
	}
	return (w);
}

t_w				ft_parse_map(char **av, t_w w)
{
	char	**tmp;
	char	*line;
	int		fd;
	int		j;

	w.m.lin = ft_count_lines(av[1]);
	if ((fd = open(av[1], O_RDONLY, S_IRUSR | S_IWUSR | S_IXUSR)) == -1)
		exit(-1);
	if (!(w.m.tab = (int **)malloc(sizeof(int *) * w.m.lin)))
		exit(-1);
	j = 0;
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		w.m.col = ft_char2_len(tmp);
		if (!(w.m.tab[j] = (int *)malloc(sizeof(int) * w.m.col)))
			exit(-1);
		w = ft_fill_tab(w, tmp, j);
		++j;
		free((void *)line);
	}
	free((void *)line);
	close(fd);
	return (w);
}
