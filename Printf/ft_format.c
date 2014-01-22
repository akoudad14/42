/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:18:31 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 11:04:34 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

int					ft_comp(char c)
{
	if (c != 'd' && c != 'n' && c != 's' && c != 'i' && c != 'c'
		&& c != 'p' && c != '%' && c != 'u' && c != 'o' && c != 'x'
		&& c != 'X' && c != 'p' && c != '%' && c != 'n' && c != 'Z')
		return (1);
	return (0);
}

t_print				*ft_fill(t_print *print, char *tmp, int j)
{
	*(tmp + j) = '\0';
	if (!(print->next = ft_lst_print(tmp, 1)))
		exit(-1);
	print = print->next;
	return (print);
}

static t_print		*ft_tmp_empty_or_full(t_print *print, char *tmp, int j)
{
	*(tmp + j) = '\0';
	j = 0;
	if (*(tmp + j) != '\0')
	{
		if (!(print->next = ft_lst_print(tmp, 0)))
			exit(-1);
		print = print->next;
	}
	return (print);
}

static t_print		*ft_finish(t_print *prt, char *tmp, t_print *beg, int j)
{
	if (*(tmp + j - 1))
	{
		*(tmp + j) = '\0';
		if (*(tmp) == '%')
		{
			if (!(prt->next = ft_lst_print(tmp, 1)))
				exit(-1);
		}
		else
		{
			if (!(prt->next = ft_lst_print(tmp, 0)))
				exit(-1);
		}
		prt = prt->next;
	}
	free((void *)tmp);
	return (beg);
}

t_print				*ft_do(char const *format, t_print *print, int i)
{
	char		*tmp;
	int			j;
	t_print		*begin;

	j = 0;
	begin = print;
	if (!(tmp = ft_strnew(ft_strlen(format))))
		exit(-1);
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			print = ft_tmp_empty_or_full(print, tmp, j);
			j = 0;
			*(tmp + j++) = *(format + i++);
			while (*(format + i) && ft_comp(*(format + i)) == 1)
				*(tmp + j++) = *(format + i++);
			*(tmp + j++) = *(format + i++);
			print = ft_fill(print, tmp, j);
			j = 0;
		}
		*(tmp + j++) = *(format + i++);
	}
	return (ft_finish(print, tmp, begin, j));
}
