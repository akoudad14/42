/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:35:08 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 09:32:49 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(*s) * (size + 1))))
		ft_error("malloc", "not enough space");
	if (s == NULL)
		return (NULL);
	s = 0;
	return ((void *)s);
}
