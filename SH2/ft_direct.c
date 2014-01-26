/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 18:38:01 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 20:54:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh2.h"
#include "libft.h"

static int		ft_check_between(char *line)
{
	char	**check;
	int		i;

	i = -1;
	if (ft_find(line, ">"))
		check = ft_strsplit(line, '>');
	else
		check = ft_strsplit(line, '<');
	if (!check)
		return (-2);
	while (i != -2 && check[++i])
	{
		check[i] = ft_strtrim(check[i]);
		if (!ft_strncmp(check[i], "", 1))
			i = -2;
	}
	ft_free_char2(check);
	return (i);
}

int				ft_direct(char *l, t_env *e)
{
	char	*new;
	char	*old;

	old = ft_strdup(l);
	new = ft_strjoin("cat ", old);
	if ((ft_find(l, ">") && ft_find(l, "<")) || ft_check_between(l) == -2)
		ft_putendl_fd("Warning: invalid null command", 2);
	else
		ft_check(new, e, ft_check_spe(new));
	gfree((void *)old);
	gfree((void *)new);
	return (0);
}
