/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:34:28 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "libft.h"
#include "ft_ls.h"

t_ls			*ft_lst(char *ls, size_t ls_size)
{
	t_ls		*new;
	size_t		i;
	char		*newls;

	i = 0;
	if (!(new = (t_ls *)malloc(sizeof(*new)))
	|| !(newls = (char *)malloc(sizeof(*newls) * ls_size)))
		return (NULL);
	ft_bzero(new, sizeof(*new));
	ft_strclr(newls);
	while (i < ls_size)
	{
		*(newls + i) = *(ls + i);
		i++;
	}
	*(newls + i) = '\0';
	new->ls = newls;
	new->ls_size = ls_size;
	new->next = NULL;
	return (new);
}

int				ft_verif(t_ls *tmp3, char *tab)
{
	while (tmp3 != NULL)
	{
		if (ft_strcmp(tmp3->ls, tab) == 0)
			return (0);
		tmp3 = tmp3->next;
	}
	return (1);
}

static void		ft_finish(t_ls *new, t_ls *really, t_ls *tmp3, t_ls *tmp2)
{
	t_ls		*tmp4;

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

t_ls			*ft_sort_lst(t_ls *new, DIR *fd)
{
	t_ls		*really;
	t_ls		*tmp;
	t_ls		*tmp2;

	if (new->next == NULL)
	{
		closedir(fd);
		return (new);
	}
	else
	{
		tmp = new;
		really = ft_lst(new->ls, new->ls_size);
		while ((new = new->next) != NULL && really != NULL)
		{
			if (ft_strcmp(really->ls, new->ls) > 0)
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
