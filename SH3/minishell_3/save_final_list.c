/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_final_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:30:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/02 17:36:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "ft_minishell3.h"
#include "libft.h"

void			ft_slist_print(t_sl *list)
{
	while (list)
	{
		ft_putchar_fd(list->c, 1);
		list = list->next;
	}
}

int				ft_slist_len(t_sl *list)
{
	int		i;
	t_sl	*move;

	move = list;
	i = 0;
	while (move)
	{
		++i;
		move = move->next;
	}
	return (i);
}

int				ft_hlist_len(t_hl *hlist)
{
	int		i;
	t_hl	*move;

	move = hlist;
	i = 0;
	while (move)
	{
		++i;
		move = move->next;
	}
	return (i);
}

static int		ft_next_next(char *buf, t_sl **list, int *cursor)
{
	if (KEY_CTRL_R(buf))
		;
	else if (KEY_CTRL_T(buf))
		;
	else if (KEY_CTRL_F(buf))
		;
	else if (KEY_CTRL_G(buf))
		;
	else if (buf[0] >= ' ' && buf[0] <= '~')
	{
		if (ft_list_put_elem(buf[0], list, *cursor) == -1)
			return (-1);
		++(*cursor);
	}
	return (0);
}

static int 		ft_next(char *buf, t_sl **list, int *cursor, t_hl **hlist)
{
	ft_putendl_fd("AAAAA", 2);
	if (*((*hlist)->ptrl) && (*hlist)->hist_nb < ft_hlist_len(*hlist) && KEY_ARROW_UP(buf))
		++((*hlist)->hist_nb);
	else if (*cursor > 0 && KEY_ARROW_DOWN(buf))
		--((*hlist)->hist_nb);
	else if (KEY_ENTER(buf))
		*cursor = -1;
	else if (*cursor > 0 && KEY_ARROW_LEFT(buf))
		--(*cursor);
	else if (*cursor < ft_slist_len(*list) && KEY_ARROW_RIGHT(buf))
		++(*cursor);
	else if (*cursor > 0 && KEY_DEL_LEFT(buf))
		ft_list_del_elem(list, --(*cursor));
	else if (*cursor < ft_slist_len(*list) && KEY_DEL_RIGHT(buf))
		ft_list_del_elem(list, *cursor);
	else if (*cursor > 0 && KEY_OPT_ARROW_LEFT(buf))
		ft_go_to_prev_word(list, cursor);
	else if (*cursor < ft_slist_len(*list) && KEY_OPT_ARROW_RIGHT(buf))
		ft_go_to_next_word(list, cursor);
	else if (KEY_CTRL_A(buf))
		*cursor = 0;
	else if (KEY_CTRL_E(buf))
		*cursor = ft_slist_len(*list);
	else
		return (ft_next_next(buf, list, cursor));
	ft_putendl_fd("BBBBBB", 2);
	return (0);
}

static void		ft_print_history(t_hl *hlist)
{
	int		i;
	t_hl	*move;

	move = hlist;
	i = -1;
	while (++i < hlist->hist_nb)
		move = move->next;
	ft_slist_print(*(move->ptrl));
}

static void		ft_print_cmd_line(t_sl **list, t_hl *hlist, int cursor, int n)
{
	int		i;

	tputs(tgetstr("cl", NULL), 1, ft_putc);
/*		ft_putnbr_fd(buf[0], 2);
		ft_putchar_fd(' ', 2);
		ft_putnbr_fd(buf[1], 2);
		ft_putchar_fd(' ', 2);
		ft_putnbr_fd(buf[2], 2);
		ft_putchar_fd(' ', 2);
		ft_putnbr_fd(buf[3], 2);
		ft_putchar_fd(' ', 2);
		ft_putnbr_fd(buf[4], 2);
		ft_putchar_fd(' ', 2);
		ft_putnbr_fd(buf[5], 2);
		ft_putchar_fd('\n', 2);*/
	if (n == hlist->hist_nb)
	{
		ft_slist_print(*list);
		i = -1;
		while (++i < ft_slist_len(*list) - cursor)
			tputs(tgetstr("le", NULL), 1, ft_putc);
	}
	else
	{
		ft_putendl_fd("GGGGG", 2);
		ft_print_history(hlist);
	}
/*	ft_putnbr_fd(cursor, 2);
	ft_putchar_fd('\n', 2);*/
}

int				ft_save_final_list(t_sl **list)
{
    int				n;
	int				cursor;
	char			buf[MAX_KEY_LEN];
	static t_hl		*hlist = NULL;

	cursor = 0;
	if (ft_add_in_history(&hlist, list) == -1)
		return (-1);
	hlist->hist_nb = 0;
	while (cursor != -1)
	{
		n = -1;
		while (++n < MAX_KEY_LEN)
			buf[n] = 0;
		if (read(STDIN_FILENO, buf, MAX_KEY_LEN) == -1)
			return (-1);
		n = hlist->hist_nb;
		if (ft_next(buf, list, &cursor, &hlist) == -1)
			return (-1);
		ft_print_cmd_line(list, hlist, cursor, n);
	}
	ft_putchar('\n');
	return (0);
}
