/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:57:00 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/18 19:19:14 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_find(char *s1, char *s2)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s2);
	while (*(s1 + i))
	{
		if (ft_strncmp(&s1[i], s2, size) == 0)
			return (1);
		++i;
	}
	return (0);
}
