/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:38:20 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/16 15:50:46 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*s3;
	unsigned char		*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (n--)
		*s3++ = *s4++;
	return (s1);
}
