/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_through_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 11:11:30 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/26 15:14:29 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

void		ft_print_tree(t_tree *t)
{
	if (t->le)
		ft_print_tree(t->le);
	ft_print_pl(t->p);
	ft_putendl("\n");
	if (t->ri)
		ft_print_tree(t->ri);
}
