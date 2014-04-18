/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:34:08 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 16:00:29 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <sys/mman.h>

void	add_block_small_2(t_block **move, size_t *remind, void *data, size_t s)
{
	static t_block		*last = NULL;
	size_t				pg;

	pg = getpagesize();
	if (*remind < sizeof(t_block *))
	{
		(*move)->next = mmap(NULL, pg, PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANON, -1, 0);
		*move = (*move)->next;
		(*move)->data = data;
		(*move)->size = s;
		(*move)->next = NULL;
		*remind = pg - sizeof(t_block *);
	}
	else
	{
		if (!last)
			last = *move;
		last += sizeof(t_block *);
		last->data = data;
		last->size = s;
		last->next = NULL;
		*remind -= sizeof(t_block *);
	}
}

void	add_block_small(t_block **list, void *data, size_t size, size_t pg)
{
	static t_block		*move = NULL;
	static size_t		remind = 4096;

	if (!move)
		move = *list;
	if (!move)
	{
		move = mmap(NULL, pg, PROT_READ | PROT_WRITE,
					MAP_PRIVATE | MAP_ANON, -1, 0);
		if (!*list)
			*list = move;
		move->data = data;
		move->size = size;
		move->next = NULL;
		remind -= sizeof(t_block *);
	}
	else
		add_block_small_2(&move, &remind, data, size);
	(*list)->last = data;
}
