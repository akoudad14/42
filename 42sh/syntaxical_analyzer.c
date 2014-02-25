/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxical_analyzer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:26:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/25 19:46:26 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"
#include "libft.h"

int		ft_error_msg(char *str)
{
	ft_putendl_fd(str, 2);
	return (-1);
}

int		ft_check_wrong_nb_of_pth(t_p *p)
{
	t_p		*move;
	int		ind_pth;

	ind_pth = 0;
	move = p;
	while (move)
	{
		if ((move->type == PTH_B && move->prev
			&& (move->prev->type == CMD || move->prev->type == ARG))
			|| (move->type == PTH_E && move->next
				&& (move->next->type == CMD || move->next->type == ARG)))
			return (ft_error_msg("Badly placed ()'s"));
		if (move->type == PTH_B)
			++ind_pth;
		if (move->type == PTH_E)
			--ind_pth;
		if (ind_pth < 0)
			return (ft_error_msg("Too many )'s."));
		move = move->next;
	}
	if (ind_pth > 0)
		ft_error_msg("Too many ('s.");
	return (0);
}

t_p		*ft_check_if_type_to_split(t_p *p, int type)
{
	t_p		*move;
	int		ind_pth;

	move = p;
	while (move)
	{
		if (move->type == PTH_B)
			++ind_pth;
		else if (move->type == PTH_E)
			--ind_pth;
		else if (ind_pth == 0 && move->type == type)
			return (move);
		move = move->next;
	}
	return (move);
}

void	ft_find_priority_operand(t_p **keep, int *type)
{
	t_p			*move;

	if ((move = ft_check_if_type_to_split(*keep, SEMI_C))
		|| (move = ft_check_if_type_to_split(*keep, OR))
		|| (move = ft_check_if_type_to_split(*keep, AND))
		|| (move = ft_check_if_type_to_split(*keep, PIPE))
		|| (move = ft_check_if_type_to_split(*keep, RED_R))
		|| (move = ft_check_if_type_to_split(*keep, RED_DR))
		|| (move = ft_check_if_type_to_split(*keep, RED_L)))
		*type = move->type;
	if (*type == OR)
	{
		while ((*keep)->type != OR && (*keep)->type != AND)
			*keep = (*keep)->next;
	}
	else if (*type == RED_R || *type == RED_DR)
	{
		while ((*keep)->type != RED_R
				&& (*keep)->type != RED_DR && (*keep)->type != RED_L)
			*keep = (*keep)->next;
	}
	else if (*type)
		*keep = move;
}

t_p		*ft_p_list_new_elem(char *tok, int type)
{
	t_p		*new;

	if (!(new = (t_p *)gmalloc(sizeof(t_p))))
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->tok = ft_strdup(tok);
	new->type = type;
	return (new);
}

int		ft_p_list_sub(t_p **list, t_p *start, t_p *end)
{
	t_p		*new;
	t_p		*move;

	move = *list;
	while (start != end)
	{
		if (!(new = ft_p_list_new_elem(start->tok, start->type)))
			return (-1);
		if (move)
		{
			move->next = new;
			new->prev = move;
		}
		move = new;
		start = start->next;
	}
	return (0);
}

int		ft_new_tree_elem(t_tree **t, t_p *p, t_p *keep)
{
	if (ft_init_tree(&((*t)->le)) == -1
		|| ft_init_tree(&((*t)->ri)) == -1)
		return (-1);
	(*t)->le->fa = *t;
	(*t)->ri->fa = *t;
	if (ft_p_list_sub(&((*t)->le->p), p, keep) == -1)
		return (-1);
	if (ft_p_list_sub(&((*t)->ri->p), keep->next, NULL) == -1)
		return (-1);
	if (ft_p_list_sub(&((*t)->p), keep, keep->next) == -1)
		return (-1);
	if ((*t)->le->p)
	{
		if (ft_syntaxical_analyzer((*t)->le->p, &((*t)->le)) == -1)
			return (-1);
	}
	if ((*t)->ri->p)
	{
		if (ft_syntaxical_analyzer((*t)->ri->p, &((*t)->ri)) == -1)
			return (-1);
	}
	return (0);
}

int		ft_put_parenthesis_in_tree(t_p *p, t_tree **t)
{
	t_p		*move;

	move = p;
	while (move && move->next)
		move = move->next;
	if (ft_init_tree(&((*t)->le)) == -1)
		return (-1);
	(*t)->le->fa = *t;
	if (ft_p_list_sub(&((*t)->le->p), p->next, move) == -1)
		return (-1);
	(*t)->p->tok = ft_strdup("()");
	(*t)->p->type = PTH;
	return (0);
}

int		ft_syntaxical_analyzer(t_p *p, t_tree **t)
{
	int		ind_pth;
	t_p		*keep;
	int		type;

	ind_pth = 0;
	keep = p;
	type = 0;
	ft_find_priority_operand(&keep, &type);
	if (type == 0 && p->type != PTH_B)
		return (0);
	else if (type == 0)
	{
		if (ft_put_parenthesis_in_tree(p, t) == -1)
			return (-1);
		return (0);
	}
	if (!keep->next || !keep->prev)
	{
		ft_putstr_fd("Badly placed ", 2);
		ft_putendl_fd(keep->tok, 2);
		return (-1);
	}
	ft_new_tree_elem(t, p, keep);
	return (0);
}
