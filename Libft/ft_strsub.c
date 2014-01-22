/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:02:35 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 09:39:46 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s2;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(*s2) * (len + 1))))
		ft_error("malloc", "not enough space");
	while (i < len)
	{
		*(s2 + i) = *(s + start);
		i++;
		start++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
