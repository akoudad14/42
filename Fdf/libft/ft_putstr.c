/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:56:05 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/27 18:20:13 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
