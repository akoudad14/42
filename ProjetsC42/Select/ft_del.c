/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 14:42:44 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 15:25:18 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_new_list(t_l *list, t_l *move, int ac)
{
	int		i;

	i = 1;
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	while (i < ac)
	{
		if (list->space == 1)
		{
			tputs(tgetstr("mr", NULL), 1, ft_putc);
			ft_putendl_fd(list->name, 2);
			tputs(tgetstr("me", NULL), 1, ft_putc);
		}
		else
			ft_putendl_fd(list->name, 2);
		list = list->next;
		i++;
	}
	tputs(tgetstr("up", NULL), 1, ft_putc);
	list = list->previous;
	while (list != move)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		list = list->previous;
	}
}

int				ft_del(t_l **list, t_l **move, int ac)
{
	t_l		*del;

	(*move)->del = 1;
	del = *list;
	if ((*list)->j == 1)
	{
		*list = (*list)->next;
		(*list)->j += 1;
	}
	else if	((*list)->j == ac - 1)
		(*list)->j = 1;
	while (del->del != (*move)->del)
		del = del->next;
	*move = (*move)->next;
	(*move)->previous = (*move)->previous->previous;
	*move = (*move)->previous;
	(*move)->next = (*move)->next->next;
	*move = (*move)->next;
	ft_destruct_link(del);
	ft_new_list(*list, *move, ac - 1);
	ft_cursor(*list, *move, ac - 1);
	return (ac - 1);
}
