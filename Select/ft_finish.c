/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 14:15:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 15:29:34 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_error_termp(char *error, char *str)
{
	ft_putstr_fd("Problem ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	exit(-1);
}

static void		ft_finish_good(int ac, t_l *list, int i)
{
	while (i < ac)
	{
		if (list->space == 1)
		{
			ft_putstr(list->name);
			list = list->next;
			++i;
			break ;
		}
		list = list->next;
		++i;
	}
	while (i < ac)
	{
		if (list->space == 1)
		{
			ft_putchar(' ');
			ft_putstr(list->name);
		}
		++i;
		list = list->next;
	}
	ft_putchar('\n');
	exit(1);
}

void			ft_choice_end(int ac, t_sel *sel, char *buf)
{
	tputs(tgetstr("te", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	sel->term.c_lflag |= ICANON;
	sel->term.c_lflag |= ECHO;
	tcsetattr(0, 0, &(sel->term));
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	if (buf[0] == 10)
		ft_finish_good(ac, sel->list, 1);
	else
		exit(1);
}
