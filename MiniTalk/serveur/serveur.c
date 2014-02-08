/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 08:49:30 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/08 19:34:13 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

t_help		help;

int			*singleton_len(void)
{
	static int		len = 0;
	return (&len);
}

int			*singleton_pid(void)
{
	static int		pid = 0;
	return (&pid);
}

void		ft_bin_to_str(int *nb_bit, char **str)
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
		if (help.one_byte[i] == '1')
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

void		ft_signal_str(int sign, int *nb_bit, char **str)
{
	static int		i = 7;

	if (sign == SIGUSR1)
	{
		help.one_byte[i] = '1';
/*		kill(pid, SIGUSR1);*/
/*		kill(pid, SIGUSR2);*/
	}
	else if (sign == SIGUSR2)
	{
		help.one_byte[i] = '0';
/*		kill(pid, SIGUSR1);*/
/*		kill(pid, SIGUSR2);*/
	}
	--i;
	if (i < 0)
	{
		i = 7;
		ft_bin_to_str(nb_bit, str);
	}
}


int		ft_bin_to_len(void)
{
	int		k;
	int		i;
	int		c;

	k = 1;
	c = 0;
	i = 32;
	while (--i >= 0)
	{
		if (help.str_len[i] == '1')
			c += k;
		k *= 2;
	}
	ft_putstr("len = ");
	ft_putnbr(c);
	ft_putchar('\n');
	return (c);
}

void		ft_signal_len(int sign, int *j, int *nb_bit)
{
	static char		*str = NULL;

	if (*j < 0)
		ft_signal_str(sign, nb_bit, &str);
	else
	{
		if (sign == SIGUSR1)
			help.str_len[*j] = '1';
		else if (sign == SIGUSR2)
			help.str_len[*j] = '0';
		--(*j);
		if (*j < 0)
		{
			*singleton_len() = ft_bin_to_len();
			str = (char *)gmalloc(sizeof(char) * (*singleton_len() + 1));
		}
	}
}

void		ft_bin_to_pid(void)
{
	int		k;
	int		i;
	int		c;

	k = 1;
	c = 0;
	i = 32;
	while (--i >= 0)
	{
		if (help.str_pid[i] == '1')
			c += k;
		k *= 2;
	}
	*singleton_pid() = c;
	ft_putstr("pid = ");
	ft_putnbr(*singleton_pid());
	ft_putchar('\n');
}

void		ft_signal_pid(int sign)
{
	static int		i = 31;
	static int		j = 31;
	static int		nb_bit = 0;

	if (nb_bit == *singleton_len() && *singleton_len() != 0)
	{
		i = 31;
		j = 31;
		nb_bit = 0;
		*singleton_len() = 0;
	}
	if (i < 0)
		ft_signal_len(sign, &j, &nb_bit);
	else
	{
		if (sign == SIGUSR1)
			help.str_pid[i] = '1';
		else if (sign == SIGUSR2)
			help.str_pid[i] = '0';
		--i;
		if (i < 0)
			ft_bin_to_pid();
	}
}

int			main(void)
{
	int		j;

	ft_putnbr(getpid());
	ft_putchar('\n');
	j = 0;
	while (j < 8)
	{
		help.one_byte[j] = '0';
		++j;
	}
	j = 0;
	while (j < 32)
	{
		help.str_pid[j] = '0';
		help.str_len[j] = '0';
		++j;
	}
	signal(SIGUSR1, ft_signal_pid);
	signal(SIGUSR2, ft_signal_pid);
	while (1)
		;
	return (0);
}
