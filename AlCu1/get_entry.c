/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:14:03 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 15:33:49 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		get_entry(int col)
{
	char	*buf;
	int		choice;

	buf = NULL;
	choice = 0;
	ft_putstr("Enter a number between 1 and ");
	ft_putnbr(col);
	ft_putchar('\n');
	while (!buf || choice > col || choice < 1)
	{
		if (!(buf = (char *)gmalloc(sizeof(char) * 1024)))
			return (-1);
		if (read(1, buf, 1024) == -1)
			return (ft_error("Read fail", "", -1));
		choice = ft_atoi(buf);
		if (choice > col || choice < 1)
		{
			ft_putstr("Enter a number between 1 and ");
			ft_putnbr(col);
			ft_putchar('\n');
		}
		gfree((void *)buf);
	}
	return (choice);
}
