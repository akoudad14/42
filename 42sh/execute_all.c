/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:22:25 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/03 15:40:30 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

/**/ #include "libft.h"
// J'ai utilise un singleton -> ft_value, pour savoir si une commande a fonctionne ou pas, il peut y avoir des cas d'erreurs, j'aimerais que vous testiez differentes cmds

// cd est presque fini , il manque quelques options -> deja fait - et sans rien, avec changement de PWD


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
		value = ft_perform_pipe(t, e); //FAIT mais probleme si premiere commande est une boucle infinie
	else if (t->p->type == PTH)
		ft_execute_all(t->le, e);
	else if (t->p->type == RED_R || t->p->type == RED_DR || t->p->type == RED_L)
		value = ft_perform_redir(t, e); //FAIT
	else if (t->p->type == CMD)
		value = ft_perform_cmd(t, e); // FAIT sauf pour les *env et une partie de cd
	return (value);
}
