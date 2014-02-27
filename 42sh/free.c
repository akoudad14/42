/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 11:55:12 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/27 11:59:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

void		ft_free_list(t_p *move)
{
	while (move->next)
	{
		move = move->next;
		if (move->prev->tok)
			gfree((void *)move->prev->tok);
		gfree((void *)move->prev);
	}
	if (move->tok)
		gfree((void *)move->tok);
	gfree((void *)move);
}

void		ft_free_tree(t_tree **t)
{
	if ((*t)->le)
		ft_free_tree(&((*t)->le));
	if ((*t)->ri)
		ft_free_tree(&((*t)->ri));
	ft_free_list((*t)->p);
	gfree((void *)*t);
}
