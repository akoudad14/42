/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:24:26 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/05 14:57:18 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"



#include <unistd.h>
int			ft_putc(int c)
{
/*	usleep(50000);*/
	ft_putchar_fd((char)c, 2);
	return (0);
}