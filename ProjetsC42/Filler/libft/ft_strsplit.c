/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:17:49 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 14:03:47 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size_word(char const *s, char c, int i)
{
	int		m;

	m = 0;
	while (*(s + i++) != c && *(s + i++))
		m++;
	return (m);
}

static char		**ft_strsplit_next(char **s3, char const *s, char c)
{
	int		i;
	int		j;
	char	*s2;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i))
			i++;
		if (*(s + i))
		{
			j = 0;
			s2 = (char *)malloc(sizeof(*s2) * (ft_size_word(s, c, i) + 1));
			while (*(s + i) != c && *(s + i))
				*(s2 + j++) = *(s + i++);
			*(s2 + j) = '\0';
			*(s3 + k++) = s2;
		}
	}
	*(s3 + k) = '\0';
	return (s3);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**s3;

	if (s == NULL)
	{
		s3 = (char **)malloc(sizeof(*s3) * (1 + 1));
		*s3 = NULL;
		return (s3);
	}
	s3 = (char **)malloc(sizeof(*s3) * (ft_wc_w(s, c) + 1));
	return (ft_strsplit_next(s3, s, c));
}
