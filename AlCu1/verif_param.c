/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:25:41 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/08 11:18:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pow4.h"

int				ft_verif_is_number(char *s)
{
	int			i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
		{
			if (i == 0 && s[i] == '-')
				return (ft_error("Avoid negative number", "", -1));
			else
				return (ft_error("Put a numeric parameters", "", -1));
		}
	}
	if (i > 9)
		return (ft_error("Put a parameters lower to 999999999", "", -1));
	return (0);
}

int				ft_verif_parameters(char *line, char *col, t_pow *pow)
{
	if (ft_verif_is_number(line) == -1 || ft_verif_is_number(col) == -1)
		return (-1);
	if ((pow->line = ft_atoi(line)) < 6)
		return (ft_error("Put a number line upper to 5", "", -1));
	if ((pow->col = ft_atoi(col)) < 7)
		return (ft_error("Put a number column upper to 6", "", -1));
	return (0);
}
