/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxical_analyzer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:26:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/26 19:07:22 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

int		ft_error_msg(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
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
			&& (move->prev->type == WORD || move->prev->type == PTH_E))
			|| (move->type == PTH_E && move->next
				&& (move->next->type == WORD || move->next->type == PTH_B)))
			return (ft_error_msg("Badly placed ", "()'s"));
		if (move->type == PTH_B)
			++ind_pth;
		if (move->type == PTH_E)
			--ind_pth;
		if (ind_pth < 0)
			return (ft_error_msg("Too many ", ")'s."));
		move = move->next;
	}
	if (ind_pth > 0)
		return (ft_error_msg("Too many ", "('s."));
	return (0);
}

t_p		*ft_check_if_type_to_split(t_p *p, int type)
{
	t_p		*move;
	int		ind_pth;

	move = p;
	ind_pth = 0;
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
	int			ind_pth;

	if ((move = ft_check_if_type_to_split(*keep, SEMI_C))
		|| (move = ft_check_if_type_to_split(*keep, OR))
		|| (move = ft_check_if_type_to_split(*keep, AND))
		|| (move = ft_check_if_type_to_split(*keep, PIPE))
		|| (move = ft_check_if_type_to_split(*keep, RED_R))
		|| (move = ft_check_if_type_to_split(*keep, RED_DR))
		|| (move = ft_check_if_type_to_split(*keep, RED_L)))
		*type = move->type;
	ind_pth = 0;
	if (*type == OR)
	{
		while ((*keep) != move)
		{
			if ((*keep)->type == PTH_B)
				++ind_pth;
			else if ((*keep)->type == PTH_E)
				--ind_pth;
			else if (ind_pth == 0 && ((*keep)->type == AND || (*keep)->type == OR))
				break ;
			*keep = (*keep)->next;
		}
	}
	else if (*type == RED_R || *type == RED_DR)
	{
		while ((*keep) != move)
		{
			if ((*keep)->type == PTH_B)
				++ind_pth;
			else if ((*keep)->type == PTH_E)
				--ind_pth;
			else if (ind_pth == 0 && ((*keep)->type == RED_R
									  || (*keep)->type == RED_DR
									  || (*keep)->type == RED_L))
				break ;
			*keep = (*keep)->next;
		}
	}
	else if (*type)
		*keep = move;
}

int		ft_syntaxical_analyzer(t_tree **t)
{
	int		ind_pth;
	t_p		*keep;
	int		type;

	ind_pth = 0;
	keep = (*t)->p;
	type = 0;
	ft_find_priority_operand(&keep, &type);
	if (type == 0 && (*t)->p->type != PTH_B)
		return (0);
	else if (type == 0)
	{
		if (ft_put_parenthesis_in_tree(t) == -1)
			return (-1);
		return (ft_syntaxical_analyzer(&((*t)->le)));
	}
	if (!keep->next || !keep->prev)
		return (ft_error_msg("Badly placed ", keep->tok));
	if (ft_new_tree_elem(t, keep) == -1)
		return (-1);
	return (0);
}
