/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:06:04 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/12 12:14:04 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

static int		ft_read(char *tab, int ret, int const fd)
{
	ret = read(fd, tab, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	tab[ret] = '\0';
	return (ret);
}

static int		ft_transfer(char **line, char *tab)
{
	char			*tmp;

	tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(*line) * 2 + 1));
	if (tmp == NULL)
		return (-1);
	ft_strclr(tmp);
	ft_strcpy(tmp, *line);
	free((void *)*line);
	*line = (char *)malloc(sizeof(**line) * ft_strlen(tmp) + 2);
	if (*line == NULL)
		return (-1);
	ft_strclr(*line);
	ft_strcpy(*line, tmp);
	free((void *)tmp);
	ft_strcat(*line, tab);
	tab[0] = '\0';
	return (1);
}

static int		ft_new_line(char **line, char *tab, int i)
{
	ft_strncat(*line, tab, i);
	ft_strcpy(tab, ft_strsub(tab, i + 1, BUFF_SIZE - i - 1));
	return (1);
}

static int		ft_one(char **line)
{
	if ((*line = (char *)malloc(sizeof(**line) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	ft_strclr(*line);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	static char		tab[BUFF_SIZE + 1];
	int				i;

	if ((ret = ft_one(line)) == -1)
		return (-1);
	while (ret > 0)
	{
		if (!tab[0])
		{
			if (!(ret = ft_read(tab, ret, fd)) && *line[0] != '\0')
				return (1);
		}
		i = 0;
		while (tab[i] && tab[i] != '\n' && ret > 0)
			i++;
		if (tab[i] == '\n' && ret > 0)
			return (ft_new_line(line, tab, i));
		else if (ret > 0)
		{
			if (ft_transfer(line, tab) == -1)
				return (-1);
		}
	}
	return (ret);
}
