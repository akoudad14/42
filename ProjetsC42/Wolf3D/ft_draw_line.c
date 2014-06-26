/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 16:32:56 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/17 16:11:25 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf3d.h"

void		ft_draw_finish(t_w w)
{
	int		i;

	i = 0;
	while (i <= IW * IH)
	{
		if (w.i.data[i * 4] == 0 && w.i.data[i * 4 + 1] == 0
			&& w.i.data[i * 4 + 2] == 0 && w.i.data[i * 4 + 3] == 0)
		{
			if (i <= (IW * IH) / 2)
			{
				w.i.data[i * 4]
					= w.draw.color / 2;
			}
			else
			{
				w.i.data[i * 4 + 2]
					= w.draw.color / 2;
			}
		}
		++i;
	}
}

void		ft_draw_line(t_w w, int x)
{
	int		j;
	int		i;

	j = w.draw.start;
	while (j <= w.draw.end)
	{
		i = 0;
		while (w.draw.helpcol <= 1 && i <= w.draw.helpcol)
		{
			w.i.data[i + x * 4 + j * w.i.sl] = w.draw.color / 2 - w.draw.color;
			++i;
		}
		while (w.draw.helpcol > 1 && i <= w.draw.helpcol - 2)
		{
			w.i.data[i + 1 + x * 4 + j * w.i.sl] = w.draw.color + w.draw.color;
			++i;
		}
		++j;
	}
}
