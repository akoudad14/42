/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:34:56 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/12 19:34:58 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			gfree(void *s)
{
	if (!(ft_list_mal(0, s)))
		return (0);
	return (1);
}
