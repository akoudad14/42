/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_mal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:49:22 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 21:23:42 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_mal	*ft_lstnew_mal(void *s)
{
	t_mal			*mal;
	int				i;

	i = 0;
	if (!(mal = (t_mal *)malloc(sizeof(*mal))))
	{
		ft_putendl_fd("Problem malloc", 2);
		return (NULL);
	}
	mal->s = s;
	mal->next = NULL;
	return (mal);
}

static t_mal	*ft_list_mal_clean(int i, void *s, t_mal *mal, t_mal *move)
{
	t_mal			*tmp;

	tmp = mal;
	if (i == 0)
	{
		while (move->s != s)
		{
			tmp = move;
			move = move->next;
		}
		mal = (move == mal) ? mal->next : mal;
		tmp->next = move->next;
		free(move->s);
		free((void *)move);
		return (mal);
	}
	while (tmp->next)
	{
		tmp = tmp->next;
		free(mal->s);
		free((void *)mal);
		mal = tmp;
	}
	free(mal->s);
	free((void *)mal);
	return (NULL);
}

void			ft_list_mal(int i, void *s)
{
	static t_mal	*mal;
	t_mal			*move;

	move = mal;
	while (mal)
	{
		ft_putendl_fd("P", 2);
		mal = mal->next;
	}
	ft_putendl_fd("\n", 2);
	mal = move;
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
		mal = ft_list_mal_clean(i, s, mal, move);
}
