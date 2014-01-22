/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:50:55 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 09:17:46 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(*s2) * (ft_strlen(s) + 1))))
		ft_error("malloc", "not enough space");
	while (*(s + i))
	{
		*(s2 + i) = f(*(s + i));
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
