/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 14:42:11 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 21:08:34 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *old, size_t size)
{
	void	*new;

	if (!(new = gmalloc(size)))
		return (NULL);
	new = ft_strcpy(new, old);
	gfree(old);
	return (new);
}
