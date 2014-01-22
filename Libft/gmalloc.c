/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:29:22 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/22 20:32:56 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*gmalloc(size_t size)
{
	void	*s;

	if (!(s = malloc(size)))
	{
		ft_putendl_fd("Problem malloc" , 2);
		return (NULL);
	}
	ft_list_mal(1, s);
	return (s);
}
