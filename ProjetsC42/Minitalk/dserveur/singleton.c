/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:23:59 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/08 21:40:55 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*singleton_len(void)
{
	static int		len = 0;

	return (&len);
}

int		*singleton_pid(void)
{
	static int		pid = 0;

	return (&pid);
}
