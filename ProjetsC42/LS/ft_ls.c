/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2015/01/30 16:55:59 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "libft.h"
#include "ft_ls.h"

t_ls	*ft_ls_t(char *dir)
{
	DIR				*fd;
	struct dirent	*e;
	t_ls			*n;
	t_ls			*tmp;

	if ((fd = opendir(dir)) == NULL)
		ft_exist_or_not(dir, 't');
	while ((e = readdir(fd)) != NULL && e->d_name[0] == '.')
		;
	n = (e != NULL) ? ft_lst(e->d_name, \
	sizeof(char *) * ft_strlen(e->d_name)) : NULL;
	tmp = n;
	while ((e = readdir(fd)) != NULL && n != NULL)
	{
		if ((e->d_name)[0] != '.')
		{
			n->next = ft_lst(e->d_name, sizeof(char *) * ft_strlen(e->d_name));
			n = n->next;
		}
	}
	if (!(n))
		return (NULL);
	return (ft_sort_lst_time(tmp, dir, fd));
}

t_ls	*ft_ls_r(char *dir)
{
	DIR				*fd;
	struct dirent	*e;
	t_ls			*n;
	t_ls			*tmp;

	if ((fd = opendir(dir)) == NULL)
		ft_exist_or_not(dir, 'r');
	while ((e = readdir(fd)) != NULL && e->d_name[0] == '.')
		;
	n = (e != NULL) ? ft_lst(e->d_name, \
	sizeof(char *) * ft_strlen(e->d_name)) : NULL;
	tmp = n;
	while ((e = readdir(fd)) != NULL && n != NULL)
	{
		if ((e->d_name)[0] != '.')
		{
			n->next = ft_lst(e->d_name, sizeof(char *) * ft_strlen(e->d_name));
			n = n->next;
		}
	}
	if (!(n))
		return (NULL);
	return (ft_sort_lst_reverse(tmp, fd));
}

t_ls	*ft_ls_l(char *dir)
{
	DIR				*fd;
	struct dirent	*e;
	t_ls			*n;
	t_ls			*tmp;

	if ((fd = opendir(dir)) == NULL)
		ft_exist_or_not(dir, 'l');
	while ((e = readdir(fd)) != NULL && (e->d_name)[0] == '.')
		;
	n = (e != NULL) ? ft_lst(e->d_name, \
	sizeof(char *) * ft_strlen(e->d_name)) : NULL;
	tmp = n;
	while ((e = readdir(fd)) != NULL && n != NULL)
	{
		if ((e->d_name)[0] != '.')
		{
			n->next = ft_lst(e->d_name, sizeof(char *) * ft_strlen(e->d_name));
			n = n->next;
		}
	}
	if (!(n))
		return (NULL);
	ft_sort_lst_l(tmp, dir);
	closedir(fd);
	return (NULL);
}

t_ls	*ft_ls_a(char *dir)
{
	DIR				*fd;
	struct dirent	*e;
	t_ls			*n;
	t_ls			*tmp;

	if ((fd = opendir(dir)) == NULL)
		ft_exist_or_not(dir, 'a');
	e = readdir(fd);
	n = (e != NULL) ? ft_lst(e->d_name, \
	sizeof(char *) * ft_strlen(e->d_name)) : NULL;
	tmp = n;
	while ((e = readdir(fd)) != NULL && n != NULL)
	{
		n->next = ft_lst(e->d_name, sizeof(char *) * ft_strlen(e->d_name));
		n = n->next;
	}
	if (!(n))
		return (NULL);
	return (ft_sort_lst(tmp, fd));
}

t_ls	*ft_ls(char *dir)
{
	DIR				*fd;
	struct dirent	*e;
	t_ls			*n;
	t_ls			*tmp;

	if ((fd = opendir(dir)) == NULL)
		ft_exist_or_not(dir, ' ');
	while ((e = readdir(fd)) != NULL && e->d_name[0] == '.')
		;
	n = (e != NULL) ? ft_lst(e->d_name, \
	sizeof(char *) * ft_strlen(e->d_name)) : NULL;
	tmp = n;
	while ((e = readdir(fd)) != NULL && n != NULL)
	{
		if ((e->d_name)[0] != '.')
		{
			n->next = ft_lst(e->d_name, sizeof(char *) * ft_strlen(e->d_name));
			n = n->next;
		}
	}
	if (!(n))
		return (NULL);
	return (ft_sort_lst(tmp, fd));
}
