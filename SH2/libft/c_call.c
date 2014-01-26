/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_call.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 11:34:40 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 19:28:38 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*c_call(char *str, void *s1)
{
	void		*s2;

	if (!ft_strcmp(str, "ft_strtrim"))
		s2 = (void *)ft_strtrim((char *)s1);
	else if (!(ft_strcmp(str, "ft_strdup")))
		s2 = (void *)ft_strdup((char *)s1);
	gfree((void *)s1);
	return (s2);
}
