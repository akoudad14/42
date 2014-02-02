/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_cursor_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 10:54:59 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/02 15:50:21 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"

void		ft_go_to_prev_word(t_sl **list, int *cursor)
{
	int		i;
	t_sl	*move;

	move = *list;
	if (*cursor > 0)
		--(*cursor);
	i = -1;
	while (++i < *cursor)
		move = move->next;
	while (*cursor > 0 && !(move->c != ' ' && (move->prev)->c == ' '))
	{
		move = move->prev;
		--(*cursor);
	}
}

void		ft_go_to_next_word(t_sl **list, int *cursor)
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
			&& !(move->c == ' ' && ((move->next)->c != ' ')))
	{
		move = move->next;
		++(*cursor);
	}
	if (*cursor < len)
		++(*cursor);
}
