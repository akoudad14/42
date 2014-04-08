/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:50:10 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/01 12:07:49 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tdel;

	if (alst == NULL)
		return ;
	tdel = *alst;
	while (tdel != NULL)
	{
		del(tdel->content, tdel->content_size);
		free(tdel);
		*alst = (*alst)->next;
		tdel = *alst;
	}
	*alst = NULL;
}
