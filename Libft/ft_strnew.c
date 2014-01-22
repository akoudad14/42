/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:03:46 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 09:33:05 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*s;
	size_t		i;

	i = 0;
	if (!(s = (char *)malloc(sizeof(*s) * (size + 1))))
		ft_error("malloc", "not enough space");
	while (i < size)
	{
		*(s + i) = '\0';
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
