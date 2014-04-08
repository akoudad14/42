/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:29:22 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/12 19:24:56 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*gmalloc(size_t size)
{
	void	*s;

	if (!(s = malloc(size)))
	{
		ft_putendl_fd("Problem malloc: not enough space" , 2);
		return (NULL);
	}
	if (!(ft_list_mal(1, s)))
		return (NULL);
	return (s);
}
