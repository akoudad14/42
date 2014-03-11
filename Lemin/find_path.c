/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 11:51:50 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/11 18:39:39 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin2.h"

int			ft_check_p(char *name, t_link *p)
{
	t_link	*move;

	move = p;
	while (move)
	{
		if (!ft_strcmp(move->name, name))
			return (0);
		move = move->prev;
	}
	return (1);
}

int			ft_find_path2(t_game *game, t_room *move, t_room *end, t_link **p)
{
	t_link		*rem;
	t_link		*new;
	t_room		*new_start;

	if (!(rem = NULL) && !(new = NULL) && !(new_start = NULL)
		&& move->tmp_link
		&& (!ft_strcmp(move->tmp_link->name, game->start)
			|| ((*p)->prev && !ft_strcmp(move->tmp_link->name,
										 (*p)->prev->name))))
		move->tmp_link = move->tmp_link->next;
	if (!move->tmp_link || ft_check_p(move->tmp_link->name, *p) == 0
		|| !(new = ft_new_link()))
		return (0);
	new->name = ft_strdup(move->tmp_link->name);
	rem = *p;
	new->prev = *p;
	(*p)->next = new;
	(*p) = (*p)->next;
	new_start = game->tmp_room;
	while (ft_strcmp(new_start->name, move->tmp_link->name))
		new_start = new_start->next;
	if (ft_find_path(game, new_start, end, p) == 1)
		return (1);
	*p = rem;
	return (2);
}

int			ft_find_path(t_game *game, t_room *start, t_room *end, t_link **p)
{
	int			ret;

	ret = 0;
	if (start && start != end)
	{
		while (start->tmp_link)
		{
			if ((ret = ft_find_path2(game, start, end, p)) == 0
				|| ret == 1)
				return (ret);
			start->tmp_link = start->tmp_link->next;
		}
	}
	if (start == end)
		return (1);
	return (0);
}
