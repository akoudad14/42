/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:58:05 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 11:09:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

char		*ft_printfc(char c)
{
	char	*tmp;

	if (!(tmp = ft_strnew(2)))
		exit(-1);
	*tmp = c;
	return (tmp);
}

char		*ft_printfp(void *p)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * 20000);
	ft_strcpy(str, "0x");
	ft_strcat(str, ft_ltoa((size_t)p, "0123456789abcdef"));
	return (str);
}

void		ft_printfn(t_print *pf, int *nbr)
{
	char	*str;
	size_t	j;

	j = 0;
	if (!(str = ft_strnew(15)))
		exit(-1);
	while (pf->i != 3)
	{
		j = j + ft_strlen(pf->str);
		pf = pf->next;
	}
	nbr[0] = j;
}
