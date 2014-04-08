/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 17:03:51 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 19:42:15 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "ft_ls.h"
#include "libft.h"

static void		ft_verif_options(char *str)
{
	int				i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != 'a' && *(str + i) != 'r'
		&& *(str + i) != 'R' && *(str + i) != 'l'
			&& *(str + i) != 't' && *(str + i) != '-')
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(*(str + i));
			ft_putchar('\n');
			ft_putendl("usage: ls [-Ralrt] [file ...]");
			free((void *)str);
			exit(-1);
		}
		i++;
	}
}

static void		ft_show(char *str, char **argv, t_ls *finish, char *tmp)
{
	int				c;

	if (!ft_compare(str, 'l') && finish == NULL)
		finish = (argv[2] == '\0') ? ft_ls_l(".") : ft_ls_l(argv[2]);
	else if (!ft_compare(str, 'l'))
	{
		ft_putndl(c = (!ft_compare(str, 'a') ? ft_total('a') : ft_total('b')));
		while (finish != NULL)
		{
			ft_info(finish, (tmp = (argv[2] == '\0' ? "." : argv[2])), 'o');
			finish = finish->next;
		}
	}
	else if (!ft_compare(str, 'R'))
		finish = (argv[2] == '\0') ? ft_ls_rec(".") : ft_ls_rec(argv[2]);
	else
	{
		finish = (finish != NULL ? finish : ft_ls(argv[1]));
		while (finish != NULL)
		{
			ft_putendl(finish->ls);
			finish = finish->next;
		}
	}
	free((void *)str);
}

static void		ft_option(char *str, char **av)
{
	t_ls			*end;
	char			*tmp;

	tmp = ".";
	end = NULL;
	ft_verif_options(str);
	if (!ft_compare(str, 'a'))
		end = (av[2] == '\0') ? ft_ls_a(".") : ft_ls_a(av[2]);
	if (!ft_compare(str, 't'))
	{
		if (end == NULL)
			end = (av[2] == '\0') ? ft_ls_t(".") : ft_ls_t(av[2]);
		else
			end = ft_sort_lst_t_two(end, (tmp = (!av[2]) ? "." : av[2]));
	}
	if (!ft_compare(str, 'r'))
	{
		if (end == NULL)
			end = (av[2] == '\0') ? ft_ls_r(".") : ft_ls_r(av[2]);
		else if (ft_compare(str, 't'))
			end = ft_sort_lst_reverse_two(end);
		else
			end = (!av[2]) ? ft_sort_r_t(end, ".") : ft_sort_r_t(end, av[2]);
	}
	ft_show(str, av, end, tmp);
}

static char		*ft_argv(char **av, char *str)
{
	int				i;

	i = 0;
	while (*(av[1]++))
	{
		if (ft_compare(str, *(av[1])) == 1)
			*(str + i++) = *(av[1]);
	}
	return (str);
}

int				main(int argc, char **av)
{
	char			*str;
	t_ls			*alone;

	if (!(str = ft_strnew(30)))
		return (0);
	if (argc == 1 || (*(av[1]) == '-' && (*(av[1] + 1) == '-'
	&& (*(av[1] + 2)) == '\0' && !av[2])))
	{
		alone = ft_ls(".");
		while (alone != NULL)
		{
			ft_putendl(alone->ls);
			alone = alone->next;
		}
		return (0);
	}
	if (*(av[1]) == '-' && *(av[1] + 1) != '\0')
		str = ft_argv(av, str);
	ft_option(str, av);
	return (0);
}
