/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:29:57 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/21 15:58:47 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_print(char **ts)
{
	int		i;

	i = -1;
	while (ts[++i])
	{
		if (i != 0)
			write(1, " ", 1);
		write(1, ts[i], ft_strlen(ts[i]));
	}
}

int		ft_echo(char **opt, char **args)
{
	int		i;

	i = -1;
	if (!ft_strcmp(opt[0], "-n"))
	{
		if (opt[1])
		{
			ft_print(opt + 1);
			write(1, " ", 1);
		}
		ft_print(args);
	}
	else
	{
		if (opt[0])
		{
			ft_print(opt);
			write(1, " ", 1);
		}
		ft_print(args);
		write(1, "\n", 1);
	}
	return (0);
}

int		main(void)
{
	char	**args;
	char	**opt;

	opt = (char **)malloc(sizeof(char *) * 2);
	args = (char **)malloc(sizeof(char *) * 2);
	opt[0] = ft_strdup("-n");
	opt[1] = NULL;
	args[0] = ft_strdup("coucou");
	args[1] = NULL;
	ft_echo(opt, args);
	return (0);
}
