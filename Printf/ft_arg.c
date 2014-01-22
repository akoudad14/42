/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 11:32:03 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 11:03:03 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include "ft_printf.h"

static int		ft_comp_opt(char *str, char c, int i)
{
	int			j;

	j = 0;
	while (j < i)
	{
		if (*(str + j) == c)
			return (1);
		j++;
	}
	return (0);
}

static char		*ft_finish(char *str)
{
	int			i;

	i = 0;
	while (*(str + i++))
	{
		if (*(str + i) == '%')
			return ("%");
		if (*(str + i) == 'Z')
			return ("Z");
	}
	return (str);
}

static char		*ft_next_opt(char *str, va_list ap, t_print *pf)
{
	int			i;

	i = 0;
	while (*(str + i++))
	{
		if (*(str + i) == 'x')
		{
			if (ft_comp_opt(str, 'l', i) == 1)
				return (ft_stoa(va_arg(ap, int), "0123456789abcdef"));
			return ((ft_toa(va_arg(ap, int), "0123456789abcdef")));
		}
		if (*(str + i) == 'X')
		{
			if (ft_comp_opt(str, 'l', i) == 1)
				return (ft_stoa(va_arg(ap, int), "0123456789ABCDEF"));
			return ((ft_toa(va_arg(ap, int), "0123456789ABCDEF")));
		}
		if (*(str + i) == 'p')
			return (ft_printfp(va_arg(ap, void *)));
		if (*(str + i) == 'n')
			ft_printfn(pf, va_arg(ap, int *));
	}
	return (ft_finish(str));
}

static char		*ft_options(char *str, va_list ap, t_print *pf)
{
	int			i;

	i = 0;
	while (*(str + i++))
	{
		if (*(str + i) == 'd' || *(str + i) == 'i')
			return (ft_itoa(va_arg(ap, int)));
		if (*(str + i) == 'c')
			return (ft_strcpy(str, ft_printfc(va_arg(ap, int))));
		if (*(str + i) == 's')
			return (va_arg(ap, char *));
		if (*(str + i) == 'u')
		{
			if (ft_comp_opt(str, 'l', i) == 1)
				return (ft_stoa(va_arg(ap, int), "0123456789"));
			return (ft_toa(va_arg(ap, int), "0123456789"));
		}
		if (*(str + i) == 'o')
		{
			if (ft_comp_opt(str, 'l', i) == 1)
				return (ft_stoa(va_arg(ap, int), "01234567"));
			return ((ft_toa(va_arg(ap, int), "01234567")));
		}
	}
	return (ft_next_opt(str, ap, pf));
}

t_print			*ft_arg(t_print *pf, va_list ap)
{
	t_print		*begin;

	begin = pf;
	while (pf)
	{
		if (pf->i == 1)
		{
			if (pf->str[1] == 'c')
				pf->i = 2;
			if (pf->str[1] == 's')
				pf->i = 0;
			if (pf->str[1] == 'n')
				pf->i = 3;
			pf->str = ft_options(pf->str, ap, begin);
			if (pf->i == 3)
				pf->i = 4;
		}
		pf = pf->next;
	}
	return (begin);
}
