/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:06:58 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/22 18:36:58 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_is_no_quote(t_sl *list, int *ind)
{
	if (list->c == '|' && list->next && list->next->c == '|')
		return (OR);
	if (list->c == '&' && list->next && list->next->c == '&')
		return (AND);
	if (list->c == '>' && list->next && list->next->c == '>')
		return (AND);
	if (list->c == ';')
		return (SEMI_C);
	if (list->c == '<')
		return (RED_L);
	if (list->c == '>')
		return (RED_R);
	if (list->c == '|')
		return (PIPE);
	if (list->c == ' ')
		return (SPACE);
	return (WORD);
}

int		ft_is_operand(t_sl *list, int *ind)
{
	if (list->prev && list->prev->c == '\\')
		return (WORD);
	if (*ind == 1 && list->c == '\'')
	{
		*ind = 0;
		return (QUO_S);
	}
	if (*ind == 2 && list->c == '\"')
	{
		*ind = 0;
		return (QUO_D);
	}
	if (*ind == 1 || *ind == 2)
		return (WORD);
	if (list->c == '\'')
	{
		*ind = 1;
		return (QUO_S);
	}
	if (list->c == '\"')
	{
		*ind = 2;
		return (QUO_D);
	}
	return (ft_is_no_quote(list, ind));
}

int		ft_new_token(t_p **p, t_sl **tl, int *type)
{
	t_p		*new;
	t_sl	*tmp;
	t_p		*move;

	if (!(new = (t_p *)gmalloc(sizeof(t_p))))
		return (NULL);
	new->tok = NULL;
	ft_do_line(&(new->tok), *tl);
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	move = *p;
	if (*p)
	{
		while (move->next)
			move = move->next;
		new->prev = move;
		move->next = new;
	}
	else
		*p = new;
	return (0);
}

int		ft_parser(t_sl *list)
{
	t_sl	*move;
	int		ind;
	t_sl	*tl;
	t_p		*p;
	int		type;
	int		tmp;

	ind = 0;
	move = list;
	p = NULL;
	tl = NULL;
	type = WORD;
	while (move)
	{
		if (tl && (tmp = ft_is_operand(move, &ind)) != type)
		{
			if (!ft_new_token(&p, &tl, type))
				return (-1);
			type = tmp;
		}
		if (ind || tmp != SPACE)
		{
			if (!tl = ft_list_new_elem(move->c))
				return (-1);
		move = move->next;
	}
	if (tmp != SPACE)
	{
		if (!ft_new_token(&p, &tl, tmp))
			return (-1);
	}
	return (0);
}
