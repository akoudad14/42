/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:15:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/09 18:12:47 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_exit(char *line)
{
	char	**ts;
	int		i;

	ts = ft_strsplim(line);
	if (ts[1])
		i = ft_atoi(ts[1]) % 256;
	else
		i = 0;
	i += 1;
	return (i);
}

static int		ft_verif_num_exit(char **ts)
{
	int		i;

	i = -1;
	while (ts[1] && ts[1][++i])
	{
		if (!ft_isdigit(ts[1][i]))
		{
			ft_putendl_fd("Num argument required between 0 and 2147483647", 2);
			ft_free_char2(ts);
			return (-1);
		}
	}
	ft_free_char2(ts);
	return (0);
}

int				ft_check_exit(char *line)
{
	char	**ts;

	ts = ft_strsplim(line);
	if (ft_strcmp(ts[0], "exit") != 0)
	{
		ft_free_char2(ts);
		return (0);
	}
	if (ft_strcmp(ts[0], "exit") == 0 && (ts[1] && ts[2]))
	{
		ft_putendl_fd("Too many arguments", 2);
		ft_free_char2(ts);
		return (-1);
	}
	if (ft_verif_num_exit(ts))
		return (-1);
	return (ft_exit(line));
}
