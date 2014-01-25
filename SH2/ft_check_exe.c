/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:19:45 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 18:47:40 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

static char		*ft_path(char *path, char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	gfree((void *)path);
	path = ft_strjoin(tmp, cmd);
	gfree((void *)tmp);
	return (path);
}

static char		*ft_finish_check(char **p, char **exe, int i)
{
	char	*path;

	path = ft_strdup(p[i]);
	ft_free_char2(p);
	ft_free_char2(exe);
	return (path);
}

char			*ft_check_exe(char *s, char *path)
{
	struct stat		*buf;
	char			**p;
	int				i;
	char			**exe;

	i = -1;
	if (!(p = ft_strsplit(path, ':')) || !(exe = ft_strsplim(s))
		|| !(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (NULL);
	if (lstat(exe[0], buf) == 0 && buf->st_mode & S_IXUSR)
	{
		gfree((void *)buf);
		ft_free_char2(p);
		return (s);
	}
	while (p[++i])
	{
		gfree((void *)buf);
		if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
			return (NULL);
		if (lstat((p[i] = ft_path(p[i], exe[0])), buf) == 0
			&& buf->st_mode & S_IXUSR)
			return (ft_finish_check(p, exe, i));
	}
	return (NULL);
}
