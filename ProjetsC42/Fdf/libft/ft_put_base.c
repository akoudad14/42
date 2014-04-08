/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:53:21 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/21 19:46:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"

unsigned int	ft_strlenn(char *base)
{
	unsigned int	i;

	i = 0;
	while (*(base + i))
		i++;
	return (i);
}

void	ft_put_base(unsigned int n, char *base)
{
	if (n < ft_strlenn(base))
		ft_putchar(base[n]);
	else
	{
		ft_put_base(n / ft_strlenn(base), base);
		ft_putchar(base[n % ft_strlenn(base)]);
	}
}
