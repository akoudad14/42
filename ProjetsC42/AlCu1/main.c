/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernar <tibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 08:54:34 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 15:36:08 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pow4.h"
#include "libft.h"

int				ft_init_game(t_pow *pow)
{
	int			i;
	int			j;

	if (!(pow->game = (char **)gmalloc(sizeof(char *) * (pow->line + 1))))
		return (-1);
	i = 0;
	while (i < pow->line)
	{
		if (!(pow->game[i] = (char *)gmalloc(sizeof(char) * (pow->col + 1))))
			return (-1);
		j = 0;
		while (j < pow->col)
		{
			pow->game[i][j] = '*';
			++j;
		}
		pow->game[i][j] = '\0';
		++i;
	}
	pow->game[i] = NULL;
	return (0);
}

int				ft_mode(void)
{
	char		*buf;
	int			mode;

	buf = NULL;
	mode = 0;
	ft_putstr("Choose a difficulty:  easy  -  medium  -  hard\n");
	while (mode == 0)
	{
		if (!(buf = (char *)gmalloc(sizeof(char) * 1024)))
			return (-1);
		if (read(1, buf, 1024) == -1)
			return (ft_error("Read fail", "", -1));
		if (ft_strncmp(buf, "easy", 4) == 0)
			mode = 1;
		else if (ft_strncmp(buf, "medium", 6) == 0)
			mode = 2;
		else if (ft_strncmp(buf, "hard", 4) == 0)
			mode = 3;
		else
			ft_putstr("Choose a difficulty:  easy  -  medium  -  hard\n");
		gfree((void *)buf);
	}
	return (mode);
}

int				main(int ac, char **av)
{
	t_pow		pow;

	if (ac < 3)
		return (ft_error("Too few arguments", "", -1));
	if (ft_verif_parameters(av[1], av[2], &pow) == -1)
		return (-1);
	if ((ac > 3 && ft_strcmp(av[3], "-p2")) || ac > 4)
		return (ft_error("Usage: puissance4 [<num>][<num>][-p2]", "", -1));
	else if (ac > 3 && !ft_strcmp(av[3], "-p2"))
		pow.mode = 3;
	else
		pow.mode = ft_mode();
	if (ft_pow4(pow, av[3]) == -1)
		return (-1);
	return (0);
}
