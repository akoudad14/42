/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 12:45:47 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 16:13:08 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh3.h"

static int		ft_listlen(t_sl *move)
{
	int		i;

	i = 0;
	while (move)
	{
		move = move->next;
		++i;
	}
	return (i);
}

int				ft_do_line(char **line, t_sl *list)
{
	int		i;
	t_sl	*move;

	move = list;
	i = ft_listlen(move);
	if (*line)
		gfree((void *)*line);
	if (!(*line = (char *)gmalloc(sizeof(char) * (i + 1))))
		return (-1);
	i = -1;
	while (move)
	{
		(*line)[++i] = move->c;
		move = move->next;
		gfree((void *)list);
		list = move;
	}
	(*line)[++i] = '\0';
	ft_putchar_fd('\n', 1);
	return (0);
}
