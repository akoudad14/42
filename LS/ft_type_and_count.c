/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_and_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/17 11:11:19 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "ft_ls.h"
#include "libft.h"

int		ft_compare(char *str, char c)
{
	int				i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_lstlen(t_ls *count)
{
	size_t			i;

	i = 0;
	while (count != NULL)
	{
		count = count->next;
		i++;
	}
	return (i);
}

int		ft_count_files(char *directory)
{
	DIR				*fd;
	int				i;
	struct dirent	*entry;

	i = 0;
	if (!(fd = opendir(directory)))
		return (0);
	while ((entry = readdir(fd)) != NULL)
		i++;
	closedir(fd);
	return (i);
}

int		ft_type_and_count_files(struct dirent *entry)
{
	if (entry->d_type == DT_DIR)
	{
		ft_putstr("d");
		return (ft_count_files(entry->d_name));
	}
	else
	{
		if (entry->d_type == DT_REG)
			ft_putstr("-");
		if (entry->d_type == DT_LNK)
			ft_putstr("l");
		if (entry->d_type == DT_FIFO)
			ft_putstr("p");
		if (entry->d_type == DT_BLK)
			ft_putstr("b");
		if (entry->d_type == DT_CHR)
			ft_putstr("c");
		if (entry->d_type == DT_SOCK)
			ft_putstr("s");
		return (1);
	}
}

int		ft_total(char c)
{
	DIR				*fd;
	struct dirent	*entry;
	blkcnt_t		l;
	struct stat		buf;

	l = 0;
	if ((fd = opendir(".")) == NULL)
		return (0);
	while ((entry = readdir(fd)) != NULL)
	{
		if ((c != 'a' && entry->d_name[0] != '.') || c == 'a')
		{
			if (lstat(entry->d_name, &buf) == -1)
				strerror(lstat(entry->d_name, &buf));
			l = l + (&buf)->st_blocks;
		}
	}
	closedir(fd);
	ft_putstr("total ");
	return (l);
}
