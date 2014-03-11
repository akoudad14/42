/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:25:34 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 15:36:56 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_put_piece(char ***game, char piece, int col, int line_max)
{
	if ((*game)[0][col] != '*')
		return (-1);
	while ((*game)[line_max][col] != '*')
		--line_max;
	(*game)[line_max][col] = piece == 'O' ? 'O' : 'X';
	return (line_max);
}
