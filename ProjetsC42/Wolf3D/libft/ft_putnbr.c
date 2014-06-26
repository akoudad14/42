/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:53:21 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/30 21:09:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	if (n <= -10)
	{
		ft_putchar('-');
		ft_putnbr(-(n / 10));
		ft_putchar(-(n % 10) + '0');
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
}
