/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 16:39:31 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/10 20:37:12 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_replace_cursor(t_l *list, t_l *move)
{
	tputs(tgetstr("up", NULL), 1, ft_putc);
	list = list->previous;
	while (list != move)
	{
		list = list->previous;
		tputs(tgetstr("up", NULL), 1, ft_putc);
	}
}

static void		ft_reverse_video(t_l *list, t_l *move)
{
	if (list == move)
	{
		tputs(tgetstr("us", NULL), 1, ft_putc);
		tputs(tgetstr("mr", NULL), 1, ft_putc);
		ft_putendl_fd(list->name, 2);
		tputs(tgetstr("ue", NULL), 1, ft_putc);
		tputs(tgetstr("me", NULL), 1, ft_putc);
	}
	else
	{
		tputs(tgetstr("mr", NULL), 1, ft_putc);
		ft_putendl_fd(list->name, 2);
		tputs(tgetstr("me", NULL), 1, ft_putc);
	}
}

void			ft_cursor(t_l *list, t_l *move, int ac)
{
	int		i;

	i = 1;
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	while (i < ac)
	{
		if (list->space == 1)
			ft_reverse_video(list, move);
		else if (list == move)
		{
			tputs(tgetstr("us", NULL), 1, ft_putc);
			ft_putendl_fd(list->name, 2);
			tputs(tgetstr("ue", NULL), 1, ft_putc);
		}
		else if (list->space != 1)
			ft_putendl_fd(list->name, 2);
		list = list->next;
		++i;
	}
	ft_replace_cursor(list, move);
}
