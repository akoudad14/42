/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_mal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:49:22 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 22:03:57 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_mal	*ft_lstnew_mal(void *s)
{
	t_mal			*mal;

	if (!(mal = (t_mal *)malloc(sizeof(*mal))))
	{
		ft_putendl_fd("Problem malloc", 2);
		return (NULL);
	}
	mal->s = s;
	mal->next = NULL;
	return (mal);
}

static void		ft_list_mal_clean(int i, void *s, t_mal **mal)
{
	t_mal			*tmp;
	t_mal			*move;

	tmp = *mal;
	move = *mal;
	if (i == 0)
	{
		while (move->s != s)
		{
			tmp = move;
			move = move->next;
		}
		*mal = (move == *mal) ? (*mal)->next : *mal;
		tmp->next = move->next;
		free(move->s);
		free((void *)move);
	}
	while (i != 0 && move)
	{
		move = move->next;
		free((*mal)->s);
		free((void *)*mal);
		*mal = move;
	}
}

void			ft_list_mal(int i, void *s)
{
	static t_mal	*mal;
	t_mal			*move;

	move = mal;
	if (mal == NULL && i == 1)
	{
		if (!(mal = ft_lstnew_mal(s)))
			return ;
	}
	else if (i == 1)
	{
		while (move->next)
			move = move->next;
		if (!(move->next = ft_lstnew_mal(s)))
			return ;
		move = move->next;
	}
	else
		ft_list_mal_clean(i, s, &mal);
}
