/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:38:24 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:28:27 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "libft.h"
#include "ft_ls.h"

t_ls		*ft_ls_rec(char *dir)
{
	DIR				*fd;
	struct dirent	*e;
	t_ls			*n;
	t_ls			*tmp;

	if ((fd = opendir(dir)) == NULL)
		ft_exist_or_not(dir, 'R');
	if ((e = readdir(fd)) != NULL)
	{
		n = ft_lst(e->d_name, sizeof (char *) * ft_strlen(e->d_name));
		tmp = n;
	}
	while ((e = readdir(fd)) != NULL && n != NULL)
	{
		n->next = ft_lst(e->d_name, sizeof(char *) * ft_strlen(e->d_name));
		n = n->next;
	}
	if (!(n))
		return (NULL);
	ft_sort_lst_recursive(tmp);
	closedir(fd);
	return (NULL);
}
