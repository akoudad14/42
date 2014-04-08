/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:18:31 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 11:07:58 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

t_print			*ft_lst_print(char *str, int i)
{
	t_print		*new;

	if (!(new = (t_print *)malloc(sizeof(*new)))
		|| !(new->str = ft_strnew(ft_strlen(str))))
		exit(-1);
	ft_strcpy(new->str, str);
	new->i = i;
	new->next = NULL;
	return (new);
}

static int		ft_free(t_print *print, char *str, int i, va_list ap)
{
	t_print		*tmp;

	tmp = print;
	while (print)
	{
		tmp = tmp->next;
		print->str = NULL;
		print->next = NULL;
		print = tmp;
	}
	free((void *)print);
	free((void *)tmp);
	free((void *)str);
	va_end(ap);
	return (i);
}

static int		ft_put(t_print *print, char *tmp, va_list ap)
{
	t_print		*begin;
	int			i;

	i = 0;
	begin = print;
	while (print)
	{
		if (print->str == NULL && (i = i + 6) > 0)
			ft_putstr("(null)");
		else if (print->i == 4)
			;
		else
		{
			if (print->str[0] == '\0' && (print->i == 1 || print->i == 2))
				i++;
			i = i + ft_strlen(print->str);
			if (print->i == 2)
				ft_putchar(print->str[0]);
			else
				ft_putstr(print->str);
		}
		print = print->next;
	}
	return (ft_free(begin, tmp, i, ap));
}

static t_print	*ft_begin(t_print *pf, char *tmp, int j)
{
	*(tmp + j) = '\0';
	if (*tmp == '%')
	{
		if (!(pf = ft_lst_print(tmp, 1)))
			exit(-1);
	}
	else
	{
		if (!(pf = ft_lst_print(tmp, 0)))
			exit(-1);
	}
	return (pf);
}

int				ft_printf(char const *fmt, ...)
{
	va_list		ap;
	int			i;
	t_print		*pf;
	char		*tmp;
	int			j;

	i = 0;
	j = 0;
	va_start(ap, fmt);
	if (!(tmp = ft_strnew(ft_strlen(fmt))) || !(pf = ft_lst_print("\0", 0)))
		return (0);
	if (*(fmt + i) == '%')
	{
		while ((*(tmp + j++) = *(fmt + i++)) && ft_comp(*(fmt + i)) == 1)
			;
		*(tmp + j++) = *(fmt + i++);
	}
	else if (*(fmt + i))
	{
		while (*(fmt + i) && *(fmt + i) != '%')
			*(tmp + j++) = *(fmt + i++);
	}
	return (ft_put(ft_arg(ft_do(fmt, ft_begin(pf, tmp, j), i), ap), tmp, ap));
}
