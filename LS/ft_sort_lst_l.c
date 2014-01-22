/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:35:40 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "libft.h"
#include "ft_ls.h"

static void		ft_finish(t_ls *new, t_ls *really, t_ls *tmp3, t_ls *tmp2)
{
	t_ls			*tmp4;

	tmp4 = new;
	while (ft_verif(tmp3, new->ls) == 0 && new != NULL)
	{
		new = new->next;
		tmp3 = tmp2;
	}
	if (new != NULL)
		really->next = ft_lst(new->ls, new->ls_size);
	while ((new = new->next) != NULL && really->next)
	{
		if (ft_strcmp(really->next->ls, new->ls) > 0
		&& ft_verif(tmp3, new->ls) == 1)
			really->next = ft_lst(new->ls, new->ls_size);
	}
	if (!(really->next))
		exit(-1);
	tmp3 = tmp2;
	new = tmp4;
	really = really->next;
	if (ft_lstlen(tmp3) < ft_lstlen(new))
		ft_finish(new, really, tmp3, tmp2);
}

static int		ft_type(struct stat *buf, char *lsl)
{
	if (buf->st_mode & S_IFREG)
		ft_putstr("-");
	else if (buf->st_mode & S_IFDIR)
	{
		ft_putstr("d");
		return (ft_count_files(lsl));
	}
	else if (buf->st_mode & S_IFCHR)
		ft_putstr("c");
	else if (buf->st_mode & S_IFBLK)
		ft_putstr("b");
	else if (buf->st_mode & S_IFIFO)
		ft_putstr("p");
	else if (buf->st_mode & S_IFLNK)
		ft_putstr("l");
	else if (buf->st_mode & S_IFSOCK)
		ft_putstr("s");
	return (1);
}

void			ft_info(t_ls *really, char *directory, char c)
{
	struct stat		buf;
	int				l;
	char			*road;

	if (!((road = ft_strnew(ft_strlen(directory + 5)))))
		exit(-1);
	ft_strcat(road, directory);
	if (c != 'l')
	{
		ft_strcat(road, "/");
		ft_strcat(road, really->ls);
	}
	if (lstat(road, &buf) == -1)
		exit(-1);
	l = ft_type(&buf, really->ls);
	ft_access(&buf);
	if (l < 10)
		ft_putstr("  ");
	else if (l < 100)
		ft_putstr(" ");
	ft_putnbr(l);
	ft_uid(&buf);
	ft_time_and_size(&buf);
	ft_putendl(really->ls);
	free(road);
}

void			ft_sort_lst_l(t_ls *new, char *directory)
{
	t_ls			*really;
	t_ls			*tmp;
	t_ls			*tmp2;

	if (new->next == NULL)
		ft_info(new, directory, 'o');
	else
	{
		tmp = new;
		really = ft_lst(new->ls, new->ls_size);
		while ((new = new->next) != NULL && really)
		{
			if (ft_strcmp(really->ls, new->ls) > 0)
				really = ft_lst(new->ls, new->ls_size);
		}
		if (!(really))
			exit(-1);
		tmp2 = really;
		ft_finish(tmp, really, tmp2, tmp2);
		ft_putndl(ft_total('b'));
		ft_info(tmp2, directory, 'o');
		while ((tmp2 = tmp2->next) != NULL)
			ft_info(tmp2, directory, 'o');
	}
}
