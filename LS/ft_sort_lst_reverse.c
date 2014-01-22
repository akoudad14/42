/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:37:42 by makoudad         ###   ########.fr       */
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
	t_ls	*tmp4;

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
		if (ft_strcmp(really->next->ls, new->ls) < 0
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

t_ls			*ft_sort_lst_reverse_two(t_ls *new)
{
	t_ls	*really;
	t_ls	*tmp;
	t_ls	*tmp2;

	if (new->next == NULL)
		return (new);
	else
	{
		tmp = new;
		really = ft_lst(new->ls, new->ls_size);
		while ((new = new->next) != NULL && really)
		{
			if (ft_strcmp(really->ls, new->ls) < 0)
				really = ft_lst(new->ls, new->ls_size);
		}
		if (!(really))
			return (NULL);
		tmp2 = really;
		ft_finish(tmp, really, tmp2, tmp2);
		return (tmp2);
	}
}

t_ls			*ft_sort_lst_reverse(t_ls *new, DIR *fd)
{
	t_ls	*really;
	t_ls	*tmp;
	t_ls	*tmp2;

	if (new->next == NULL)
	{
		closedir(fd);
		return (new);
	}
	else
	{
		tmp = new;
		really = ft_lst(new->ls, new->ls_size);
		while ((new = new->next) != NULL && really)
		{
			if (ft_strcmp(really->ls, new->ls) < 0)
				really = ft_lst(new->ls, new->ls_size);
		}
		if (!(really))
			return (NULL);
		tmp2 = really;
		ft_finish(tmp, really, tmp2, tmp2);
		closedir(fd);
		return (tmp2);
	}
}
