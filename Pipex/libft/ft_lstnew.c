/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:02:23 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/01 18:13:32 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static t_list	*ft_new(void const *content, size_t content_size, t_list *new)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)malloc(sizeof(*ptr) * content_size);
	if (ptr == NULL)
		return (NULL);
	while (i < content_size)
	{
		*(ptr + i) = *((unsigned char *)content + i);
		i++;
	}
	new->content = ptr;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	return (ft_new(content, content_size, new));
}
