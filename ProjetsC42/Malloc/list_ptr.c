/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:21:39 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 17:12:53 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

void		add_block_large(t_block **list, void *data, size_t size)
{
	static t_block	*move = NULL;

	if (!move)
		move = *list;
	if (move == NULL)
		move = mmap(NULL, size, PROT_READ | PROT_WRITE,
					MAP_PRIVATE | MAP_ANON, -1, 0);
	else
	{
		move->next = mmap(NULL, size, PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANON, -1, 0);
		move = move->next;
	}
	if (!*list)
		*list = move;
	move->data = data;
	move->size = size;
	move->next = NULL;
	(*list)->last = data;
}

int			check_finish_del(t_block **move, t_block **block, void *data)
{
	if ((*move)->data == data)
	{
		ft_memset((*move)->data, 0, (*move)->size);
		(*move)->size = 0;
		return (0);
	}
	*move = (*block)->next;
	*block = (*block)->next;
	return (-1);
}

int			del_block(t_block **list, void *data, void *last, size_t pg)
{
	t_block		*block;
	t_block		*move;
	size_t		i;

	block = *list;
	move = *list;
	while (move)
	{
		i = 0;
		while (i < pg && move && move->data != last)
		{
			if (move->data == data)
			{
				ft_memset(move->data, 0, move->size);
				move->size = 0;
				return (0);
			}
			move += sizeof(t_block *);
			i += sizeof(t_block *);
		}
		if (check_finish_del(&move, &block, data) == 0)
			return (0);
	}
	return (-1);
}

void		del_block_large(t_block **list, void *data, size_t size, size_t pg)
{
	t_block		*block;
	t_block		*move;
	size_t		i;

	i = 1;
	while (pg * i < size)
		++i;
	pg *= i;
	block = *list;
	while (move)
	{
		if (move->data == data)
		{
			if (move == *list)
				*list = (*list)->next;
			else
				block->next = block->next->next;
			move->next = NULL;
			munmap(move, pg);
			return ;
		}
		if (block != move)
			block = block->next;
		move = move->next;
	}
}

void		list_ptr(void *data, size_t size, int flag)
{
	static t_block	*tiny = NULL;
	static t_block	*small = NULL;
	static t_block	*large = NULL;
	size_t			pg;

	pg = getpagesize();
	if (flag == 1)
	{
		if (size < (3 * pg / 100))
			add_block_tiny(&tiny, data, size, pg);
		else if (size < pg)
			add_block_small(&small, data, size, pg);
		else
			add_block_large(&large, data, size);
	}
	else if (flag == -1)
	{
		if (del_block(&tiny, data, tiny->last, pg) == -1)
		{
			if (del_block(&small, data, small->last, pg) == -1)
				del_block_large(&large, data, size, pg);
		}
	}
	else if (flag == 0)
		show_block(tiny, small, large);
}
