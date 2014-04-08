/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 19:32:19 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/04 18:58:01 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_sqrt(double n)
{
	double	precision;
	double	elem;

	precision = 0.00001;
	elem = n;
	while ((elem * elem >= n + precision) || (elem * elem <= n - precision))
		elem = (elem + n / elem) / 2;
	return (elem);
}
