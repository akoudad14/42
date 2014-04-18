/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 10:24:21 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/16 15:52:59 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"
#include <stdlib.h>

void	*realloc(void *ptr, size_t size)
{
	void	*data;

	data = malloc(size);
	data = ft_memcpy(data, ptr, size);
	free(ptr);
	return (data);
}
