/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 13:26:37 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/14 19:34:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "librace.h"

/*static t_race	*ft_add_first(char *key, char *val, t_race *list)
{
	t_race		*new;
	t_race		*first;

	new = ft_lst_race(key, val);
	first = new;
	new->next = list;
	return (first);
}

static t_race	*ft_lstcpy(t_race *list)
{
    if (!list)
        return (NULL);
    else
		return (ft_add_first(list->key, list->val, ft_lstcpy(list->next)));
}

static t_race	*ft_fusion(t_race *lef, t_race *rig)
{
    if (!lef)
		return (ft_lstcpy(rig));
    else if (!rig)
        return ft_lstcpy(lef);
    else if (ft_strcmp(lef->key, rig->key) <= 0)
        return (ft_add_first(lef->key, lef->val, ft_fusion(lef->next, rig)));
    else
        return (ft_add_first(rig->key, rig->val, ft_fusion(lef, rig->next)));
 }

static void		ft_split(t_race *list, t_race **left, t_race **right)
{
	while (list)
	{
		if (list)
		{
			*left = ft_add_first(list->key, list->val, *left);
  			list = list->next;
		}
		if (list)
		{
			*right = ft_add_first(list->key, list->val, *right);
			list = list->next;
		}
	}
}

t_race			*ft_fus_sort(t_race *list)
{
	t_race		*left;
	t_race		*right;
	t_race		*l_sorted;
	t_race		*r_sorted;
	t_race		*result;

    if (!list || !list->next)
        return (ft_lstcpy(list));
    else
	{
        left = NULL;
        right = NULL;
        ft_split(list, &left, &right);
        l_sorted = ft_fus_sort(left);
        r_sorted = ft_fus_sort(right);
        free_list(left);
        free_list(right);
        result = ft_fusion(l_sorted, r_sorted);
        free_list(l_sorted);
		free_list(r_sorted);
        return (result);
    }
	}*/
