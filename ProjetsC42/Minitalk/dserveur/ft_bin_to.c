/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:24:47 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/08 21:38:13 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_bin_to_str(int *nb_bit, char **str, t_help *help)
{
	int				k;
	int				i;
	int				c;
	static int		j = 0;

	k = 1;
	c = 0;
	i = 8;
	while (--i >= 0)
	{
		if (help->one_byte[i] == '1')
			c += k;
		k *= 2;
	}
	(*str)[j] = c;
	++j;
	++(*nb_bit);
	if (*nb_bit == *singleton_len())
	{
		(*str)[j] = '\0';
		ft_putendl(*str);
		j = 0;
		gfree((void *)*str);
	}
}

int			ft_bin_to_len(t_help *help)
{
	int		k;
	int		i;
	int		c;

	k = 1;
	c = 0;
	i = 32;
	while (--i >= 0)
	{
		if (help->str_len[i] == '1')
			c += k;
		k *= 2;
	}
	return (c);
}

void		ft_bin_to_pid(t_help *help)
{
	int		k;
	int		i;
	int		c;

	k = 1;
	c = 0;
	i = 32;
	while (--i >= 0)
	{
		if (help->str_pid[i] == '1')
			c += k;
		k *= 2;
	}
	*singleton_pid() = c;
}
