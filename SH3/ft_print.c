/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:01:20 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/05 18:33:57 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_minishell3.h"

void		ft_slist_print(t_sl *list, int co)
{
	int		i;

	i = P_LEN;
	while (list)
	{
		ft_putchar_fd(list->c, 2);
		list = list->next;
		++i;
		if (i % co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
}

void		ft_hlist_print(t_hl **hlist, int *cursor, t_sl **list, int flag)
{
	if ((*hlist)->next && flag == 1)
		*hlist = (*hlist)->next;
	else if ((*hlist)->prev && flag == -1)
		*hlist = (*hlist)->prev;
	*list = ft_listdup((*hlist)->hist);
	*cursor = ft_slist_len(*list);
}
