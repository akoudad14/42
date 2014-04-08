/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 14:19:39 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/10 20:43:02 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_l		*ft_reinit(t_l *list, t_l *move)
{
	while (list->j > 0)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		--list->j;
	}
	move = list;
	list->j = 1;
	return (list);
}

static t_l		*ft_select_or_not(t_l *move)
{
	if (move->space == 0)
	{
		tputs(tgetstr("mr", NULL), 1, ft_putc);
		ft_putendl_fd(move->name, 2);
		move->space = 1;
		tputs(tgetstr("me", NULL), 1, ft_putc);
	}
	else
	{
		ft_putendl_fd(move->name, 2);
		move->space = 0;
	}
	return (move);
}

void			ft_space(t_l **list, t_l **move, int ac)
{
	*move = ft_select_or_not(*move);
	if ((*move)->space == 1 && (*list)->j < ac -1)
	{
		(*list)->j += 1;
		*move = (*move)->next;
	}
	else if ((*move)->space == 1)
		*move = ft_reinit(*list, *move);
	else
		tputs(tgetstr("up", NULL), 1, ft_putc);
	ft_cursor(*list, *move, ac);
}
