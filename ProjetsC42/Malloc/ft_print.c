/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 16:01:45 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 17:23:57 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

void		ft_print(t_block *move)
{
	char	*str;

	str = ft_toh((size_t)move->data, "0123456789ABCDEF");
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
	ft_putstr(" - ");
	str = ft_toh((size_t)move->data + move->size, "0123456789ABCDEF");
	ft_putstr(str);
	free(str);
	ft_putstr(": ");
	ft_put_base(move->size, "0123456789");
	ft_putendl(" octets");
}
