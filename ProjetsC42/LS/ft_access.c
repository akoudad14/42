/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:27:38 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

void	ft_exist_or_not(char *directory, char c)
{
	t_ls			*file;

	if (ft_verif_dir(directory) != 0)
	{
		ft_putstr("ls: ");
		ft_putstr(directory);
		ft_putendl(": No such file or directory");
		exit(-1);
	}
	if (ft_verif_dir(directory) == 0)
	{
		if (c == 'l')
		{
			if (!(file = ft_lst(directory, ft_strlen(directory))))
				exit(-1);
			ft_info(file, directory, 'l');
		}
		else
			ft_putendl(directory);
		exit(-1);
	}
}

int		ft_verif_dir(char *unknown)
{
	struct stat		verif;

	if (lstat(unknown, &verif) == -1)
		strerror(lstat(unknown, &verif));
	if ((&verif)->st_mode & S_IFDIR)
		return (1);
	return (0);
}

void	ft_access(struct stat *buf)
{
	char			a;

	ft_putchar(a = ((S_IRUSR & buf->st_mode) ? 'r' : '-'));
	ft_putchar(a = ((S_IWUSR & buf->st_mode) ? 'w' : '-'));
	if (buf->st_mode & S_ISUID)
		ft_putchar(a = ((0100 & buf->st_mode) ? 's' : 'S'));
	else
		ft_putchar(a = ((S_IXUSR & buf->st_mode) ? 'x' : '-'));
	ft_putchar(a = ((S_IRGRP & buf->st_mode) ? 'r' : '-'));
	ft_putchar(a = ((S_IWGRP & buf->st_mode) ? 'w' : '-'));
	if (buf->st_mode & S_ISGID)
		ft_putchar(a = ((0010 & buf->st_mode) ? 's' : 'S'));
	else
		ft_putchar(a = ((S_IXGRP & buf->st_mode) ? 'x' : '-'));
	ft_putchar(a = ((S_IROTH & buf->st_mode) ? 'r' : '-'));
	ft_putchar(a = ((S_IWOTH & buf->st_mode) ? 'w' : '-'));
	if (buf->st_mode & S_ISVTX)
		ft_putchar(a = ((0001 & buf->st_mode) ? 't' : 'T'));
	else
		ft_putchar(a = ((S_IXOTH & buf->st_mode) ? 'x' : '-'));
	ft_putstr("  ");
}

void	ft_uid(struct stat *buf)
{
	struct passwd	*wuid;
	struct group	*gid;

	if (!(wuid = getpwuid(buf->st_uid)))
		exit(-1);
	ft_putchar(' ');
	ft_putstr(wuid->pw_name);
	ft_putstr("  ");
	if (!(gid = getgrgid(buf->st_gid)))
		exit(-1);
	ft_putstr(gid->gr_name);
}

void	ft_time_and_size(struct stat *buf)
{
	time_t			timep;

	timep = buf->st_mtime;
	if (buf->st_size < 10)
		ft_putstr("      ");
	else if (buf->st_size < 100)
		ft_putstr("     ");
	else if (buf->st_size < 1000)
		ft_putstr("    ");
	else if (buf->st_size < 10000)
		ft_putstr("   ");
	else
		ft_putstr("  ");
	ft_putnbr(buf->st_size);
	ft_putstr(" ");
	ft_putstr(ft_strsub(ctime(&timep), 4, 12));
	ft_putchar(' ');
}
