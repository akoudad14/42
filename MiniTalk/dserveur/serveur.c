/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 08:49:30 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/08 21:36:42 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "serveur.h"
#include "libft.h"

t_help		help;

void		ft_signal_str(int sign, int *nb_bit, char **str)
{
	static int		i = 7;

	if (sign == SIGUSR1)
		help.one_byte[i] = '1';
	else if (sign == SIGUSR2)
		help.one_byte[i] = '0';
	--i;
	if (i < 0)
	{
		i = 7;
		ft_bin_to_str(nb_bit, str, &help);
	}
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
			*singleton_len() = ft_bin_to_len(&help);
			str = (char *)gmalloc(sizeof(char) * (*singleton_len() + 1));
		}
	}
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
			ft_bin_to_pid(&help);
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
