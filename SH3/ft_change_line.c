/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:39:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/04 20:12:49 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <string.h>
#include <unistd.h>
#include "ft_minishell3.h"

int		ft_change_line(char *buf, t_sl **list, int *cursor, int co)
{
	int					len;

	len = ft_slist_len(*list);
	if (KEY_OPT_ARROW_UP(buf) && (P_LEN + *cursor) >= co)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		*cursor -= co + 1;
		while (++(*cursor) < 0)
			tputs(tgetstr("nd", NULL), 1, ft_putc);
	}
	else if (KEY_OPT_ARROW_DOWN(buf)
			&& ((P_LEN + *cursor) / co) < ((P_LEN + len) / co))
	{
		tputs(tgetstr("do", NULL), 1, ft_putc);
		if ((((P_LEN + *cursor) / co) + 1) < ((P_LEN + len) / co))
			*cursor += co;
		else
			*cursor = len;
		tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + *cursor) % co), 1, ft_putc);
	}
	else
		return (1);
	return (0);
}

