/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst_recursive.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:30:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "libft.h"
#include "ft_ls.h"

static void		ft_again(t_ls *tmp2, t_ls *real, t_ls *lst, struct stat tat)
{
	while (real != NULL)
	{
		if (lstat(real->ls, &tat) == -1)
			exit(-1);
		if ((&tat)->st_mode & S_IFDIR)
		{
			if (!(lst->next = ft_lst(real->ls, real->ls_size)))
				exit(-1);
			lst = lst->next;
		}
		real = real->next;
	}
	while (tmp2 != NULL)
	{
		if (tmp2->ls[0] != '.')
		{
			ft_putstr("./");
			ft_putstr(tmp2->ls);
			ft_putendl(":");
			ft_ls_rec(tmp2->ls);
		}
		tmp2 = tmp2->next;
	}
}

static void		ft_find_directory(t_ls *really, t_ls *tmp2)
{
	t_ls			*last;
	struct stat		tat;

	last = ft_lst(NULL, 0);
	while (last->ls_size == 0)
	{
		if (lstat(really->ls, &tat) == -1)
			exit(-1);
		if ((&tat)->st_mode & S_IFDIR)
		{
			if (!(last = ft_lst(really->ls, really->ls_size)))
				exit(-1);
			tmp2 = last;
		}
		really = really->next;
	}
	ft_again(tmp2, really, last, tat);
}

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

void			ft_sort_lst_recursive(t_ls *new)
{
	t_ls			*really;
	t_ls			*tmp;
	t_ls			*tmp2;

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
	really = tmp2;
	while (really != NULL)
	{
		if (really->ls[0] != '.')
			ft_putendl(really->ls);
		really = really->next;
	}
	ft_find_directory(tmp2, tmp2);
}
