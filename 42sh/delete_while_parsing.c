/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_while_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 18:48:26 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/24 19:27:19 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"
#include "libft.h"

static void		ft_delete_plist_last_elem(t_p **p, t_p **move)
{
	if ((*move)->prev)
		(*move)->prev->next = NULL;
	if (*move == *p)
	{
		gfree((void *)(*move)->tok);
		gfree((void *)(*move));
		*p = NULL;
	}
	else
	{
		gfree((void *)(*move)->tok);
		gfree((void *)(*move));
	}
	*move = NULL;
}

static void		ft_delete_plist_elem(t_p **p, t_p **move)
{
	t_p		*tmp;

	tmp = *move;
	if ((*move)->next)
	{
		*move = (*move)->next;
		if (*p == (*move)->prev)
			*p = (*p)->next;
		if (tmp->prev)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		gfree((void *)tmp->tok);
		gfree((void *)tmp);
	}
	else
		ft_delete_plist_last_elem(p, move);
}

int				ft_delete_quotes_and_spaces(t_p **p, int ind)
{
	t_p		*move;

	move = *p;
	while (move)
	{
		if (move->type == SPACE || move->type == QUO_S || move->type == QUO_D)
			ft_delete_plist_elem(p, &move);
		else
			move = move->next;
	}
	if (ind)
	{
		ft_putstr_fd("Unmatched ", 2);
		if (ind == 1)
			ft_putendl_fd("\'.", 2);
		else
			ft_putendl_fd("\".", 2);
		return (-1);
	}
	return (0);
}

static int		ft_token_without_backslashes(char **tok)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = (char *)gmalloc(sizeof(char) * (ft_strlen(*tok) + 1))))
		return (-1);
	j = -1;
	i = -1;
	while ((*tok)[++i])
	{
		if ((*tok)[i] == '\\')
		{
			if ((*tok)[++i])
				ret[++j] = (*tok)[i];
			else
				return (-2);
		}
		else
			ret[++j] = (*tok)[i];
	}
	ret[++j] = '\0';
	gfree((void *)(*tok));
	*tok = ft_strdup(ret);
	gfree((void *)ret);
	return (0);
}

int				ft_delete_backslashes(t_p **p)
{
	t_p		*move;
	int		cont;

	move = *p;
	while (move)
	{
		if (move->type == WORD && ft_find(move->tok, "\\"))
		{
			if ((cont = ft_token_without_backslashes(&(move->tok))) == -2)
			{
				ft_putendl_fd("Parse error near \'\\\'", 2);
				return (-1);
			}
			else if (cont == -1)
				return (-1);
		}
		move = move->next;
	}
	return (0);
}
