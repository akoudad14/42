/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:01:20 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 19:21:51 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh3.h"

static void		ft_slist_print(t_sl *list, int co)
{
	int		i;

	i = P_LEN;
	while (list)
	{
		ft_putchar_fd(list->c, 1);
		list = list->next;
		++i;
		if (i % co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
}

static int		ft_clean(int old_line, int cursor_line)
{
	int		i;

	i = old_line;
	while (i < cursor_line)
	{
		tputs(tgetstr("do", NULL), 1, ft_putc);
		++i;
	}
	while (i > cursor_line)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		--i;
	}
	return (0);
}

int				ft_print(t_sl *list, t_save *save, int old_line)
{
	int		cursor_line;
	int		i;
	char	*go;

	cursor_line = (P_LEN + save->cursor_l) / save->co;
	if (list)
		ft_clean(old_line, cursor_line);
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_putc);
	i = cursor_line + 1;
	while (list && --i > 0)
		tputs(tgetstr("up", NULL), 1, ft_putc);
	tputs(tgetstr("cd", NULL), 1, ft_putc);
	ft_putstr_fd("_$> ", 1);
	ft_slist_print(list, save->co);
	if (list && save->cursor_l != ft_slist_len(list))
	{
		go = tgoto(tgetstr("ch", NULL), 0, (P_LEN + save->cursor_l) % save->co);
		tputs(go, 1, ft_putc);
		i = ((P_LEN + ft_slist_len(list)) / save->co) + 1;
		while (--i > cursor_line)
			tputs(tgetstr("up", NULL), 1, ft_putc);
	}
	return (0);
}
