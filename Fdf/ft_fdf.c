/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 10:39:51 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 16:47:59 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft.h"
#include "ft_fdf.h"

static int			ft_count_elem(t_fdf *list)
{
	int			i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

static int			ft_size(t_fdf *list)
{
	int			n;

	n = 0;
	while (list)
	{
		if (ft_count_wd(list->line, ' ') > n)
			n = ft_count_wd(list->line, ' ');
		list = list->next;
	}
	return (n);
}

static t_fdf		*ft_lstnew_fdf(char *str)
{
	t_fdf		*list;

	if (!(list = (t_fdf *)malloc(sizeof(*list)))
		|| !(list->line = ft_strnew(ft_strlen(str))))
		return (NULL);
	ft_strcpy(list->line, str);
	list->next = NULL;
	return (list);
}

static void			ft_find_number(t_fdf *list, int nb_line, int nb_col)
{
	int			i;
	int			j;
	int			**tab;
	char		**tmp;

	if (!(tab = (int **)malloc(sizeof(*tab) * nb_line * nb_line)))
		exit(-1);
	i = 0;
	while (i < nb_line)
	{
		j = 0;
		if (!(tab[i] = (int *)malloc(sizeof(**tab) * nb_col)))
			exit(-1);
		tmp = ft_strsplit(list->line, ' ');
		while (j < nb_col)
		{
			tab[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		list = list->next;
		i++;
	}
	ft_draw_grid(nb_line, nb_col, tab);
}

int					main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_fdf		*list;
	t_fdf		*first;

	argc = 0;
	if (!(list = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	if ((fd = open(argv[1], S_IRUSR)) == -1)
		return (0);
	if (get_next_line(fd, &line))
	{
		list = ft_lstnew_fdf(line);
		first = list;
	}
	while (get_next_line(fd, &line))
	{
		list->next = ft_lstnew_fdf(line);
		list = list->next;
	}
	ft_find_number(first , ft_count_elem(first), ft_size(first));
	return (0);
}
