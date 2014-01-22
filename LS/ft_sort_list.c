/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 13:26:37 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/15 11:23:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "ft_ls.h"
#include "libft.h"

static void		free_list(t_ls *list)
{
	t_ls		*tmp;

	tmp = list;
	while ((list = tmp))
	{
		tmp = tmp->next;
		list->ls = NULL;
		list->ls_size = 0;
		list->next = NULL;
		free((void *)list);
	}
}

static t_ls		*ft_add_first(char *ls, size_t ls_size, t_ls *list)
{
	t_ls		*new;
	t_ls		*first;

	new = ft_lst(ls, ls_size);
	first = new;
	new->next = list;
	return (first);
}

static t_ls	*ft_lstcpy(t_ls *list)
{
    if (!list)
        return (NULL);
    else
		return (ft_add_first(list->ls, list->ls_size, ft_lstcpy(list->next)));
}

static t_ls		*ft_fusion(t_ls *lef, t_ls *rig, int r)
{
    if (!lef)
		return (ft_lstcpy(rig));
    else if (!rig)
        return ft_lstcpy(lef);
    else if ((ft_strcmp(lef->ls, rig->ls) * r) <= 0)
        return (ft_add_first(lef->ls, lef->ls_size, ft_fusion(lef->next, rig, r)));
    else
        return (ft_add_first(rig->ls, rig->ls_size, ft_fusion(lef, rig->next,r)));
 }

static void		ft_split(t_ls *list, t_ls **left, t_ls **right)
{
	while (list)
	{
		if (list)
		{
			*left = ft_add_first(list->ls, list->ls_size, *left);
  			list = list->next;
		}
		if (list)
		{
			*right = ft_add_first(list->ls, list->ls_size, *right);
			list = list->next;
		}
	}
}

t_ls			*ft_fus_sort(t_ls *list, int r)
{
	t_ls		*left;
	t_ls		*right;
	t_ls		*l_sorted;
	t_ls		*r_sorted;
	t_ls		*result;

    if (!list || !list->next)
        return (ft_lstcpy(list));
    else
	{
        left = NULL;
        right = NULL;
        ft_split(list, &left, &right);
        l_sorted = ft_fus_sort(left, r);
        r_sorted = ft_fus_sort(right, r);
        free_list(left);
        free_list(right);
        result = ft_fusion(l_sorted, r_sorted, r);
        free_list(l_sorted);
		free_list(r_sorted);
        return (result);
    }
}
