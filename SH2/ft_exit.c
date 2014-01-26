/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:15:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 18:05:30 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_check_exit(char *line)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_strsplim(line);
	if (ft_strcmp(tab[0], "exit") != 0)
		return (ft_free_char2(tab));
	if (ft_strcmp(tab[0], "exit") == 0 && (tab[1] && tab[2]))
	{
		ft_putendl_fd("Too many arguments", 2);
		return (-1 + ft_free_char2(tab));
	}
	while (tab[1] && tab[1][++i])
	{
		if (!ft_isdigit(tab[1][i]))
		{
			ft_putendl_fd("Numeric argument required", 2);
			return (-1 + ft_free_char2(tab));
		}
	}
	ft_free_char2(tab);
	return (1);
}

int			ft_exit(char *line)
{
	char	**tab;
	int		i;

	tab = ft_strsplim(line);
	if (tab[1])
		i = ft_atoi(tab[1]) % 256;
	else
		i = 0;
	cfree();
	return (i);
}
