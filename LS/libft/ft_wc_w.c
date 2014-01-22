/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:37:21 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/05 13:07:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wc_w(char const *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (*(s + i))
	{
		if (*((char *)s + i) == c && *((char *)s + i + 1) != c
			&& *((char *)s + i + 1) != '\0')
			j++;
		i++;
	}
	return (j);
}