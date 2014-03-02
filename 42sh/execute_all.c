/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:22:25 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/02 12:39:22 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

#include "libft.h" //DEBUG
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
		value = ft_execute_all(t->le, e);
		if (value == -1)
			value = ft_execute_all(t->ri, e);
	}
	else if (t->p->type == PIPE)
		value = ft_perform_pipe(t, e); //FAIT
	else if (t->p->type == PTH)
		ft_execute_all(t->le, e);
	else if (t->p->type == RED_R || t->p->type == RED_DR || t->p->type == RED_L)
		value = ft_perform_redir(t, e); //FAIT
	else if (t->p->type == CMD)
		value = ft_perform_cmd(t, e);
	return (value);
}
