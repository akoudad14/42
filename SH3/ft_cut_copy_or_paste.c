/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_copy_or_paste.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:49:24 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/05 21:02:35 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell3.h"

static int		ft_cut_left(t_sl **list, t_save *save)
{
	int		i;

	i = -1;
	if (save->cut)
	{
		free((void *)save->cut);
		save->cut = NULL;
	}
	while (++i < save->cursor)
	{
		if (ft_list_put_elem((*list)->c, &(save->cut), i))
			return (-1);
		*list = (*list)->next;
	}
	if (*list)
		(*list)->prev = NULL;
	save->cursor = 0;
	return (0);
}

static int		ft_cut_right(t_sl **list, t_save *save)
{
	t_sl	*move;
	int		i;

	move = *list;
	i = -1;
	while (++i < save->cursor)
		move = move->next;
	if (save->cut)
	{
		free((void *)save->cut);
		save->cut = NULL;
	}
	if (move && move->next)
	{
		move = move->next;
		save->cut = ft_listdup(move);
		move->prev->next = NULL;
	}
	return (0);
}

static int		ft_paste(t_sl **list, t_save *save)
{
	t_sl	*move;

	move = save->cut;
	while (move)
	{
		if (ft_list_put_elem(move->c, list, save->cursor))
			return (-1);
		++(save->cursor);
		move = move->next;
	}
	return (0);
}

int				ft_cut_copy_or_paste(char *buf, t_sl **list, t_save *save)
{
	if (*list && KEY_CTRL_R(buf))
		ft_cut_left(list, save);
	else if (*list && KEY_CTRL_T(buf))
		ft_cut_right(list, save);
	else if (*list && KEY_CTRL_F(buf))
	{
		if (save->cut)
		{
			free((void *)save->cut);
			save->cut = NULL;
		}
		save->cut = ft_listdup(*list);
		*list = NULL;
		save->cursor = 0;
	}
	else if (save->cut && KEY_CTRL_G(buf))
		ft_paste(list, save);
	else
		return (1);
	return (0);
}
