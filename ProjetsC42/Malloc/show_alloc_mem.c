/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 16:18:05 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 17:24:12 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"
#include <stdlib.h>
#include <unistd.h>

void	show_block_t_and_s_2(t_block **move, size_t *nb, void *last)
{
	size_t		pg;
	size_t		i;

	pg = getpagesize();
	i = 0;
	while (i < pg && *move && (*move)->data != last)
	{
		if ((*move)->size != 0)
		{
			ft_print(*move);
			*nb += (*move)->size;
		}
		i += sizeof(t_block *);
		*move += sizeof(t_block *);
	}
	if (*move && (*move)->data == last && (*move)->size != 0)
	{
		ft_print(*move);
		*nb += (*move)->size;
	}
}

void	show_block_t_and_s(t_block *list, size_t *nb, void *last)
{
	t_block		*move;
	t_block		*block;
	char		*str;

	block = list;
	move = list;
	str = ft_toh((size_t)move->data, "0123456789ABCDEF");
	ft_putstr("0x");
	ft_putendl(str);
	free(str);
	while (move)
	{
		show_block_t_and_s_2(&move, nb, last);
		move = block->next;
		block = block->next;
	}
}

void	show_block_l(t_block *list, size_t *nb)
{
	t_block		*move;
	char		*str;

	move = list;
	str = ft_toh((size_t)move->data, "0123456789ABCDEF");
	ft_putstr("0x");
	ft_putendl(str);
	free(str);
	while (move)
	{
		if (move->size != 0)
		{
			ft_print(move);
			*nb += move->size;
			move = move->next;
		}
	}
}

void	show_block(t_block *tiny, t_block *small, t_block *large)
{
	size_t		nb;
	void		*last_t;
	void		*last_s;

	nb = 0;
	last_t = tiny->last;
	last_s = small->last;
	if (tiny)
	{
		ft_putstr("TINY : ");
		show_block_t_and_s(tiny, &nb, last_t);
	}
	if (small)
	{
		ft_putstr("SMALL : ");
		show_block_t_and_s(small, &nb, last_s);
	}
	if (large)
	{
		ft_putstr("LARGE : ");
		show_block_l(large, &nb);
	}
	ft_putstr("Total : ");
	ft_put_base(nb, "0123456789");
	ft_putendl(" octets");
}

void	show_alloc_mem(void)
{
	list_ptr(NULL, 0, 0);
}
