/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_final_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:30:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/03 22:05:59 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "ft_minishell3.h"
#include "libft.h"

static int		ft_fast_move(char *buf, t_sl **list, int *cursor)
{
	if (*cursor > 0 && KEY_OPT_ARROW_LEFT(buf))
		ft_go_to_prev_word(list, cursor);
	else if (*cursor < ft_slist_len(*list) && KEY_OPT_ARROW_RIGHT(buf))
		ft_go_to_next_word(list, cursor);
	else if (KEY_CTRL_A(buf))
	{
		*cursor += 1;
		while (--(*cursor))
			tputs(tgetstr("le", NULL), 1, ft_putc);
	}
	else if (KEY_CTRL_E(buf))
	{
		*cursor -= 1;
		while (++(*cursor) < ft_slist_len(*list))
			tputs(tgetstr("nd", NULL), 1, ft_putc);
	}
	return (0);
}


static int		ft_little_move(char *buf, t_sl **list, int *cursor)
{
	if (KEY_ARROW_LEFT(buf) && *cursor)
	{
		--(*cursor);
		tputs(tgetstr("le", NULL), 1, ft_putc);
	}
	else if (*cursor < ft_slist_len(*list) && KEY_ARROW_RIGHT(buf))
	{
		tputs(tgetstr("nd", NULL), 1, ft_putc);
		++(*cursor);
	}
	else if (*cursor > 0 && KEY_DEL_LEFT(buf))
	{
		tputs(tgetstr("le", NULL), 1, ft_putc);
		tputs(tgetstr("dc", NULL), 1, ft_putc);
		ft_list_del_elem(list, --(*cursor));
	}
	else if (*cursor < ft_slist_len(*list) && KEY_DEL_RIGHT(buf))
	{
		ft_list_del_elem(list, *cursor);
		tputs(tgetstr("dc", NULL), 1, ft_putc);
	}
	else
		return (ft_fast_move(buf, list, cursor));
	return (0);
}

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
		return (ft_little_move(buf, list, &save->cursor));
	return (0);
}

static int 		ft_check(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	int		i;

	i = save->cursor + 1;
	if (KEY_ENTER(buf))
		save->cursor = -1;
	else if (buf[0] >= ' ' && buf[0] <= '~' && buf[1] == 0)
	{
		if (ft_list_put_elem(buf[0], list, save->cursor) == -1)
			return (-1);
		tputs(tgetstr("im", NULL), 1, ft_putc);
		ft_putchar_fd(buf[0], 2);
		tputs(tgetstr("ei", NULL), 1, ft_putc);
		save->hist_nb = 0;
		if (*hlist)
		{
			while ((*hlist)->prev)
				*hlist = (*hlist)->prev;
		}
		++(save->cursor);
	}
	else
		return (ft_historic(buf, list, save, hlist));
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
