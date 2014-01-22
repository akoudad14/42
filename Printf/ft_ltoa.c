/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:27:12 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 11:06:33 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

static char		*ft_ltoa_next(size_t n, char *s, int i, char *b)
{
	int			j;

	i++;
	j = i;
	while (i > 0)
	{
		*(s + i - 1) = b[n % ft_strlen(b)];
		n = n / ft_strlen(b);
		i--;
	}
	*(s + j) = '\0';
	return (s);
}

char			*ft_ltoa(size_t n, char *base)
{
	char		*s;
	int			i;
	size_t		k;

	i = 0;
	k = n;
	s = (char *)malloc(sizeof(*s) * 12000);
	if (s == NULL)
		return (NULL);
	if (n == 0)
	{
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}
	while (k >= ft_strlen(base))
	{
		i++;
		k = k / ft_strlen(base);
	}
	return (ft_ltoa_next(n, s, i++, base));
}
