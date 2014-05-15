/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 18:53:42 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/15 19:22:58 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"

void	ft_ls(void)
{
	DIR				*fd;
	struct dirent	*ls;
	if (!(fd = opendir(".")))
	{
		ft_putendl("ls fail");
		return ;
	}
	while ((ls = readdir(fd)))
	{
		if (ls->d_name[0] != '.')
			ft_putendl(ls->d_name);
	}
	closedir(fd);
}
