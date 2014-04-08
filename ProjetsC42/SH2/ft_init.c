/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 10:27:01 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 15:13:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"
#include "libft.h"

int		ft_init(t_env *e, char **env)
{
	if (!ft_check_env_and_signal(env))
		return (-2);
	if (!(e->envc = ft_copy_tab_tab(env)))
		return (-2);
	if (!(e->env = ft_copy_tab_tab(env)))
		return (-2);
	ft_putstr("42makoudad$> ");
	return (0);
}
