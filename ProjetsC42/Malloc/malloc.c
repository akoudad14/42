/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 10:24:10 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 15:59:51 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>
#include <unistd.h>

void	*malloc_tiny(size_t size, size_t pg)
{
	void			*data;
	static size_t	remind = 3 * 4096;
	static void		*ptr = NULL;

	if (remind < size)
		remind = pg;
	if (3 * pg == remind)
	{
		if ((data = mmap(NULL, 3 * pg, PROT_READ | PROT_WRITE,
						MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
			return (NULL);
		ptr = data;
		ptr += size;
	}
	else
	{
		data = ptr;
		ptr += size;
	}
	remind -= size;
	return (data);
}

void	*malloc_small(size_t size, size_t pg)
{
	void			*data;
	static size_t	remind = 100 * 4096;
	static void		*ptr = NULL;

	if (remind < size)
		remind = 100 * pg;
	if (100 * pg == remind)
	{
		if ((data = mmap(NULL, 100 * pg, PROT_READ | PROT_WRITE,
						MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
			return (NULL);
		ptr = data;
		ptr += size;
	}
	else
	{
		data = ptr;
		ptr += size;
	}
	remind -= size;
	return (data);
}

void	*malloc_large(size_t size)
{
	void	*data;

	if ((data = mmap(NULL, size, PROT_READ | PROT_WRITE,
					MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
		return (NULL);
	return (data);
}

void	*malloc(size_t size)
{
	void	*data;
	size_t	pg;

	pg = getpagesize();
	if (size < (3 * pg / 100))
		data = malloc_tiny(size, pg);
	else if (size < pg)
		data = malloc_small(size, pg);
	else
		data = malloc_large(size);
	list_ptr(data, size, 1);
	return (data);
}
