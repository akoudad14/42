/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:15:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/02 14:45:28 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "42sh.h"

static int		ft_verif_num_exit(char *num)
{
	int		i;

	i = -1;
	while (num[++i])
	{
		if (num[i] != '-' && !(ft_isdigit((int)num[i])))
			return (-1);
	}
	return (0);
}

int			ft_exit(t_p *p)
{
	int		status;

	status = 0;
	if (!p->next)
	{
		ft_putendl("exit");
		exit(status);
	}
	else if (p->next->next
			|| ((ft_verif_num_exit(p->next->tok)) == -1))
		return (ft_error_msg("exit: Expression Syntax", ""));
	else
	{
		status = ft_atoi(p->next->tok) % 256;
		ft_putendl("exit");
		exit(status);
	}
	return (0);
}
