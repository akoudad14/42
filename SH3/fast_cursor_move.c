/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_cursor_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 10:54:59 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/04 19:58:10 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <string.h>
#include "libft.h"
#include "ft_minishell3.h"

void		ft_go_to_prev_word(t_sl **list, int *cursor, int co)
{
	int		i;
	t_sl	*move;

	move = *list;
	if (*cursor > 0)
	{
		--(*cursor);
		tputs(tgetstr("le", NULL), 1, ft_putc);
		if ((P_LEN + *cursor + 1) % co == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putc);
			tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + *cursor) % co), 1, ft_putc);
		}
	}
	i = -1;
	while (++i < *cursor)
		move = move->next;
	while (*cursor > 0 && move && move->prev
			&& !(move->c != ' ' && (move->prev)->c == ' '))
	{
		move = move->prev;
		--(*cursor);
		tputs(tgetstr("le", NULL), 1, ft_putc);
		if ((P_LEN + *cursor + 1) % co == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putc);
			tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + *cursor) % co), 1, ft_putc);
		}
	}
}

void		ft_go_to_next_word(t_sl **list, int *cursor, int co)
{
	int		i;
	t_sl	*move;
	int		len;

	len = ft_slist_len(*list);
	move = *list;
	i = -1;
	while (++i < *cursor)
		move = move->next;
	while (*cursor < len && move && move->next
			&& !(move->c == ' ' && (move->next)->c != ' '))
	{
		move = move->next;
		++(*cursor);
		tputs(tgetstr("nd", NULL), 1, ft_putc);
		if ((P_LEN + *cursor) % co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
	if (*cursor < len)
	{
		++(*cursor);
		tputs(tgetstr("nd", NULL), 1, ft_putc);
		if ((P_LEN + *cursor) % co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
}
