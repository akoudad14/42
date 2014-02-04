/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:01:20 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/04 11:18:17 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_minishell3.h"

void		ft_slist_print(t_sl *list)
{
	while (list)
	{
		ft_putchar_fd(list->c, 2);
		list = list->next;
	}
}


void		ft_print(t_hl **hlist, int *cursor, t_sl **list, int flag)
{
	int		i;

	i = 0;
	if ((*hlist)->next && flag == +1)
		*hlist = (*hlist)->next;
	else if ((*hlist)->prev && flag == -1)
		*hlist = (*hlist)->prev;
	i = *cursor;
	i += 1;
	while (--i)
		tputs(tgetstr("le", NULL), 1, ft_putc);
	tputs(tgetstr("cd", NULL), 1, ft_putc);
	*list = ft_listdup((*hlist)->hist);
	ft_slist_print(*list);
	*cursor = ft_slist_len(*list);
}
