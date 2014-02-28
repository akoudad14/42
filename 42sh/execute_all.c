/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:22:25 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/28 19:08:02 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_perform_pipe()
}

int		ft_execute_all(t_tree *t, t_env *e)
{
	int		value;

	value = 0;
	if (t->p->type == SEMI_C)
	{
		ft_execute_all(t->le, e);
		ft_execute_all(t->ri, e);
	}
	else if (t->p->type == AND)
	{	
		value = ft_execute_all(t->le, e);
		if (value != -1)
			value = ft_execute_all(t->ri, e);
	}
	else if (t->p->type == OR)
	{
		ft_execute_all(t->le, e);
		if (value == -1)
			value = ft_execute_all(t->ri, e);
	}
	else if (t->p->type == PIPE)
	{
		ft_perform_pipe();
		ft_execute_all(t->le, e);
		ft_execute_all(t->ri, e);
	}
	else if (t->p->type == PTH)
	{
		ft_execute_all(t->le, e);
	}
	else if (t->p->type == RED_R || t->p->type == RED_DR || t->p->type == RED_G)
	{
		ft_perform_redir();
		ft_execute_all(t->le, e);
	}
	else if (t->p->type == CMD)
		value = ft_perform_cmd();
	return (value);
}
