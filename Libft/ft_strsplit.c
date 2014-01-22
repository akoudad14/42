/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:17:49 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 09:47:08 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_s_w(char const *s, char c, int i)
{
	int		m;

	m = 0;
	while (*(s + i) && *(s + i) != c)
	{
		++i;
		++m;
	}
	return (m);
}

static char		*ft_fill_t(char *s3, char c, int *i, char const *s)
{
	int		j;

	j = 0;
	while (*(s + *i) != c && *(s + *i))
	{
		s3[j++] = *(s + *i);
		i[0] += 1;
	}
	s3[j] = '\0';
	return (s3);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**s3;
	int		i;
	int		k;

	if (!(s3 = (char **)malloc(sizeof(*s3) * (ft_wc_w(s, c) + 1))))
		ft_error("malloc", "not enough space");
	i = 0;
	k = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i))
			++i;
		if (*(s + i))
		{
			if (!(s3[k] = (char *)malloc(sizeof(char) * (ft_s_w(s, c, i) + 1))))
				ft_error("malloc", "not enough space");
			s3[k] = ft_fill_t(s3[k], c, &i, s);
			++k;
		}
	}
	if (!(s3[k] = (char *)malloc(sizeof(char) * (1 + 1))))
		ft_error("malloc", "not enough space");
	s3[k] = '\0';
	return (s3);
}
