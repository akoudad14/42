/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 18:53:42 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/16 11:16:42 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"

char	*ft_ls(void)
{
	DIR				*fd;
	struct dirent	*ls;
	char			*tab;

	tab = "";
	ls = NULL;
	if (!(fd = opendir(".")))
	{
		ft_putendl("ls fail");
		return (NULL);
	}
	while ((ls = readdir(fd)))
	{
		if (ls->d_name[0] != '.')
		{
			tab = ft_strjoin(tab, ls->d_name);
			tab = ft_strjoin(tab, "/");
		}
	}
	closedir(fd);
	return (tab);
}
