/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:42:04 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 16:05:43 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_toh_next(size_t n, char *s, int i, char *base)
{
	int		j;

	i++;
	j = i;
	while (i > 0)
	{
		*(s + i - 1) = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		i--;
	}
	*(s + j) = '\0';
	return (s);
}

char			*ft_toh(size_t n, char *base)
{
	char	*s;
	int		i;
	size_t	k;

	i = 0;
	k = n;
	if (!(s = (char *)malloc(sizeof(*s) * 50)))
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
	return (ft_toh_next(n, s, i++, base));
}
