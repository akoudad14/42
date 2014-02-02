/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 15:54:01 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/02 17:21:56 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_minishell3.h"

static t_hl		*ft_hlist_create_new_elem(t_sl **list)
{
	t_hl	*new;

	if (!(new = (t_hl *)malloc(sizeof(*new))))
		return (NULL);
	new->ptrl = list;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int				ft_add_in_history(t_hl **hlist, t_sl **list)
{
	t_hl	*new_elem;

	if (!(new_elem = ft_hlist_create_new_elem(list)))
		return (-1);
	if (!*hlist)
		*hlist = new_elem;
	else
	{
		new_elem->next = *hlist;
		(*hlist)->prev = new_elem;
		*hlist = new_elem;
	}
	return (0);
}
