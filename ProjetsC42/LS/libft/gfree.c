/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:41:19 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/05 10:38:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			gfree(void *s)
{
	if (!(ft_list_mal(0, s)))
		return (0);
	return (1);
}