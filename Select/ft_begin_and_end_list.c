/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_and_end_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 21:22:31 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/10 20:49:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_destruct_link(t_l *del)
{
	del->next = NULL;
	del->previous = NULL;
	free((void *)del);
}

void	ft_free_list(t_l *list)
{
	t_l		*tmp;

	tmp = list;
	while (list)
	{
		tmp = tmp->next;
		list->next = NULL;
		free((void *)list->name);
		free((void *)list);
		list = tmp;
	}
	free((void *)tmp);
}

t_l		*ft_do_list(int ac, char **av, int i)
{
	t_l		*list;
	t_l		*begin;
	t_l		*tmp;

	while (i < ac)
	{
		if (!(list = ft_lstnew_sel(av[i])))
			exit(-1);
		begin = list;
		i++;
		while (i < ac)
		{
			if (!(list->next = ft_lstnew_sel(av[i])))
				exit(-1);
			tmp = list;
			list = list->next;
			list->previous = tmp;
			i++;
		}
	}
	list->next = begin;
	tmp = list;
	list = list->next;
	list->previous = tmp;
	return (list);
}

t_l		*ft_lstnew_sel(char *name)
{
	t_l		*new;

	if (!(new = (t_l *)malloc(sizeof(*new)))
		|| !(new->name = (char *)malloc(sizeof(char) * ft_strlen(name) + 1)))
		exit(-1);
	ft_strcpy(new->name, name);
	new->previous = NULL;
	new->next = NULL;
	new->space = 0;
	new->del = 0;
	return (new);
}
