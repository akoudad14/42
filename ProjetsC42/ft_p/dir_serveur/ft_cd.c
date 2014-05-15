/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:47:33 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/15 19:02:25 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"

int			ft_cd(char *rep)
{
	struct stat		*buf;
	int				value1;
	int				value2;

	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (-1);
	value1 = chdir(rep);
	value2 = lstat(rep, buf);
	if (value1 == -1 && value2 == 0
		&& !(buf->st_mode & S_IFREG))
		return (ft_error(rep, ": Permission denied", -1));
	else if (value1 == -1 && value2 == 0)
		return (ft_error(rep, ": Not a directory", -1));
	else if (value1 == -1 && value2 == -1)
		return (ft_error(rep, ": No such file or directory", -1));
	return (0);
}

void	ft_back(char *str, char **path)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*path) - 2;
	while ((*path)[len] != '/')
		--len;
	tmp = ft_strsub(*path, 0, len + 1);
	*path = ft_strdup(tmp);
	gfree(tmp);
	ft_cd(str);
}
