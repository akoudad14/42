/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:01:26 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/30 21:13:15 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t'
	|| *str == '\f' || *str == '\r')
		str++;
	if ((str[0] == '+' && str[1] == '-') || (str[0] == '-' && str[1] == '+'))
		return (0);
	if (*str == '-')
	{
		i = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		j = *str - '0' + j * 10;
		str++;
	}
	return (j * i);
}
