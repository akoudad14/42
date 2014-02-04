/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_final_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:30:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/04 20:14:31 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include "ft_minishell3.h"
#include "libft.h"

static int		ft_historic(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	if (KEY_ARROW_UP(buf) && *hlist && save->hist_nb < ft_hlist_len(*hlist))
	{
		if (save->hist_nb)
			ft_print(hlist, &(save->cursor), list, +1);
		else
			ft_print(hlist, &(save->cursor), list, 0);
		++(save->hist_nb);
	}
	else if (KEY_ARROW_DOWN(buf) && *hlist && save->hist_nb)
	{
		--(save->hist_nb);
		if (save->hist_nb > 0)
			 ft_print(hlist, &save->cursor, list, -1);
		else
		{
			save->cursor = ft_slist_len(*list) + 1;
			*list = NULL;
			while (--save->cursor)
				tputs(tgetstr("le", NULL), 1, ft_putc);
			tputs(tgetstr("cd", NULL), 1, ft_putc);
		}
	}
	else
		return (1);
	return (0);
}

static int		ft_fast_move(char *buf, t_sl **list, int *cursor, int co)
{
	if (*cursor > 0 && KEY_OPT_ARROW_LEFT(buf))
		ft_go_to_prev_word(list, cursor, co);
	else if (*cursor < ft_slist_len(*list) && KEY_OPT_ARROW_RIGHT(buf))
		ft_go_to_next_word(list, cursor, co);
	else if (KEY_CTRL_A(buf))
	{
		while (*cursor - co > 0)
		{
			*cursor -= co;
			tputs(tgetstr("up", NULL), 1, ft_putc);
		}
		tputs(tgetstr("up", NULL), 1, ft_putc);
		tputs(tgetstr("do", NULL), 1, ft_putc);
		*cursor = 0;
		tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + *cursor) % co), 1, ft_putc);
	}
	else if (KEY_CTRL_E(buf))
	{
		*cursor -= 1;
		while (++(*cursor) < ft_slist_len(*list))
		{
			if ((P_LEN + *cursor) % co == 0)
				tputs(tgetstr("do", NULL), 1, ft_putc);
			tputs(tgetstr("nd", NULL), 1, ft_putc);
		}
	}
	else
		return (1);
	return (0);
}

static int		ft_little_move(char *buf, t_sl **list, int *cursor, int co)
{
	if (*cursor > 0 && KEY_ARROW_LEFT(buf))
	{
		--(*cursor);
		tputs(tgetstr("le", NULL), 1, ft_putc);
		if (((P_LEN + *cursor + 1) % co) == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putc);
			tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + *cursor) % co), 1, ft_putc);
		}
	}
	else if (*cursor < ft_slist_len(*list) && KEY_ARROW_RIGHT(buf))
	{
		++(*cursor);
		tputs(tgetstr("nd", NULL), 1, ft_putc);
		if ((P_LEN + *cursor) % co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
	else if (*cursor > 0 && KEY_DEL_LEFT(buf))
	{
		--(*cursor);
		tputs(tgetstr("le", NULL), 1, ft_putc);
		if (((P_LEN + *cursor + 1) % co) == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putc);
			tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + *cursor) % co), 1, ft_putc);
		}
		tputs(tgetstr("dc", NULL), 1, ft_putc);
		ft_list_del_elem(list, *cursor);
	}
	else if (*cursor < ft_slist_len(*list) && KEY_DEL_RIGHT(buf))
	{
		tputs(tgetstr("dc", NULL), 1, ft_putc);
		ft_list_del_elem(list, *cursor);
	}
	else
		return (1);
	return (0);
}

static int		ft_put_char(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	if (buf[0] >= ' ' && buf[0] <= '~' && buf[1] == 0)
	{
		if (ft_list_put_elem(buf[0], list, save->cursor) == -1)
			return (-1);
		tputs(tgetstr("im", NULL), 1, ft_putc);
		ft_putchar_fd(buf[0], 2);
		tputs(tgetstr("ei", NULL), 1, ft_putc);
		if (save->hist_nb)
		{
			save->hist_nb = 0;
			while ((*hlist)->prev)
				*hlist = (*hlist)->prev;
		}
		++(save->cursor);
		if ((save->cursor + P_LEN) % save->co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
	else
		return (1);
	return (0);
}

static int 		ft_check(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	int					do_it;
	struct winsize		w;

	do_it = 1;
	if (KEY_ENTER(buf))
	{
		do_it = 0;
		save->cursor = -1;
	}
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	save->co = w.ws_col;
	if (do_it && (do_it = ft_put_char(buf, list, save, hlist)) == -1)
		return (-1);
	if (do_it && (do_it = ft_little_move(buf, list, &(save->cursor), save->co)) == -1)
		return (-1);
	if (do_it && (do_it = ft_change_line(buf, list, &(save->cursor), save->co)) == -1)
		return (-1);
	if (do_it && (do_it = ft_fast_move(buf, list, &(save->cursor), save->co)) == -1)
		return (-1);
	if (do_it && (do_it = ft_historic(buf, list, save, hlist)) == -1)
		return (-1);
/*	while (do_it < save->cursor)
	tputs(tgetstr("nd", NULL), 1, ft_putc);*/
/*	do_it = -1;
	while (++do_it < MAX_KEY_LEN)
	{
		ft_putnbr_fd(buf[do_it], 2);
		ft_putchar_fd(' ', 2);
		}*/
/*	tputs(tgoto(tgetstr("ch", NULL), 0, save->co), 1, ft_putc);
 */	/*save->fd = open("plouf.txt", O_RDWR | O_APPEND | O_CREAT, 0644);
	ft_putstr_fd("cursor = " , save->fd);
	ft_putnbr_fd((save->cursor) % save->co, save->fd);
	ft_putendl_fd("", save->fd);
	ft_putstr_fd("len = " , save->fd);
	ft_putnbr_fd((P_LEN + ft_slist_len(*list)) / save->co, save->fd);
	ft_putendl_fd("", save->fd);
	ft_putstr_fd("colcursor = " , save->fd);
	ft_putnbr_fd((save->cursor + P_LEN) / save->co, save->fd);
	ft_putendl_fd("", save->fd);
	close(save->fd);*/
	return (0);
}

int				ft_save_final_list(t_sl **list, t_hl **hlist)
{
	int				n;
	char			buf[MAX_KEY_LEN];
	t_hl			*move;
	t_save			save;

	save.cursor = 0;
	save.hist_nb = 0;
	move = *hlist;
	ft_putstr("_$> ");
	while (save.cursor != -1)
	{
		n = -1;
		while (++n < MAX_KEY_LEN)
			buf[n] = 0;
		if (read(STDIN_FILENO, buf, MAX_KEY_LEN) == -1)
			return (-1);
		if (ft_check(buf, list, &save, &move) == -1)
			return (-1);
	}
	if (ft_in_history(hlist, list) == -1)
		return (-1);
	ft_putchar('\n');
	return (0);
}
