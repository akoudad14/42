/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:35:08 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/30 19:34:18 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*s;

	s = (char *)malloc(sizeof(*s) * (size + 1));
	if (s == NULL)
		return (NULL);
	s = 0;
	return ((void *)s);
}
