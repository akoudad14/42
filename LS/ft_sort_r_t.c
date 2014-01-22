/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_r_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:39:59 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "libft.h"
#include "ft_ls.h"

char			*ft_road(char *road, char *directory, char *file)
{
	ft_strcpy(road, "./");
	ft_strcat(road, directory);
	ft_strcat(road, "/");
	ft_strcat(road, file);
	return (road);
}

int				ft_strcmp_time_two(char *dst, char *src, char *directory)
{
	struct stat		buf2;
	struct stat		buf3;
	char			*road;

	if (!(road = ft_strnew(100)))
		perror(road);
	if (ft_strcmp(directory, ".") != 0)
	{
		dst = ft_strdup(ft_road(road, directory, dst));
		src = ft_strdup(ft_road(road, directory, src));
	}
	free((void *)road);
	if (lstat(dst, &buf2) == -1 || lstat(src, &buf3) == -1)
		strerror(lstat(dst, &buf2));
	if ((&buf2)->st_mtime > ((&buf3)->st_mtime))
		return (1);
	if ((&buf2)->st_mtime == ((&buf3)->st_mtime))
	{
		if (ft_strcmp(dst, src) == 0)
			return (0);
		else if (ft_strcmp(dst, src) < 0)
			return (1);
	}
	return (-1);
}

static int		ft_verif_two(t_ls *tmp3, char *tab, char *directory)
{
	while (tmp3 != NULL)
	{
		if (ft_strcmp_time_two(tmp3->ls, tab, directory) == 0)
			return (0);
		tmp3 = tmp3->next;
	}
	return (1);
}

static void		ft_end(t_ls *new, t_ls *really, char *dir, t_ls *tmp2)
{
	t_ls			*tmp4;
	t_ls			*tmp3;

	tmp3 = tmp2;
	tmp4 = new;
	while (ft_verif_two(tmp3, new->ls, dir) == 0 && new != NULL)
	{
		new = new->next;
		tmp3 = tmp2;
	}
	if (new != NULL)
		really->next = ft_lst(new->ls, new->ls_size);
	while ((new = new->next) != NULL && really->next)
	{
		if (ft_verif_two(tmp3, new->ls, dir) == 1
		&& ft_strcmp_time_two(really->next->ls, new->ls, dir) == 1)
			really->next = ft_lst(new->ls, new->ls_size);
	}
	if (!(really->next))
		exit(-1);
	tmp3 = tmp2;
	new = tmp4;
	really = really->next;
	if (ft_lstlen(tmp3) < ft_lstlen(new))
		ft_end(new, really, dir, tmp2);
}

t_ls			*ft_sort_r_t(t_ls *new, char *directory)
{
	t_ls			*really;
	t_ls			*tmp;
	t_ls			*tmp2;

	if (new->next == NULL)
		return (new);
	else
	{
		tmp = new;
		really = ft_lst(new->ls, new->ls_size);
		while ((new = new->next) != NULL && really)
		{
			if (ft_strcmp_time_two(really->ls, new->ls, directory) == 1)
				really = ft_lst(new->ls, new->ls_size);
		}
		if (!(really))
			return (NULL);
		tmp2 = really;
		ft_end(tmp, really, directory, tmp2);
		return (tmp2);
	}
}
