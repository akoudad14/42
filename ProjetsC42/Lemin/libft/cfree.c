/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:45:55 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 14:04:03 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			cfree(void)
{
	if (!(ft_list_mal(-1, NULL)))
		return (-1);
	return (0);
}
