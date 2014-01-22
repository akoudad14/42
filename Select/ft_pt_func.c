/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 14:59:56 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 15:09:35 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_putc(int c)
{
	ft_putchar_fd(c, 2);
	return (0);
}

void		ft_sign(int sign)
{
	if (sign == SIGQUIT)
		return ;
}
