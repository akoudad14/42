/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 11:12:34 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 14:41:14 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pow4.h"
#include "libft.h"

void		ft_finish(int check, int play, int player)
{
	ft_putstr("\033[32m");
	if (check == 0 && play == player)
		ft_putendl("Congratulations to player: you win -_-");
	else if (check == 0)
		ft_putendl("Congratulations to computer: you win !!");
	else
		ft_putendl("Draw: it's sad :'(");
	ft_putstr("\033[0m");
}

void		ft_multiplayer(t_pow pow, int nb_turn_max)
{
	char	play;
	int		nb_turn;
	int		check;
	int		col_ch;
	int		li_ch;

	nb_turn = 0;
	play = 'O';
	col_ch = -1;
	li_ch = -1;
	while ((check = ft_check_alignment(pow, li_ch, col_ch - 1)) != 0
				&& nb_turn != nb_turn_max)
	{
		col_ch = get_entry(pow.col);
		while ((li_ch = ft_put_piece(&pow.game, play,
										col_ch - 1, pow.line - 1)) == -1)
			col_ch = get_entry(pow.col);
		play = (play == 'O') ? 'X' : 'O';
		++nb_turn;
		ft_put_game(pow, col_ch);
	}
	ft_finish(check, play, pow.player);
}

void		ft_player_vs_i_a(t_pow pow, int nb_turn_max)
{
	char	play;
	int		nb_turn;
	int		check;
	int		col_ch;
	int		li_ch;

	nb_turn = 0;
	play = 'O';
	col_ch = -1;
	li_ch = -1;
	while ((check = ft_check_alignment(pow, li_ch, col_ch - 1)) != 0
				&& nb_turn != nb_turn_max)
	{
		col_ch = (play == pow.player)
			? ft_virtual_play(pow, nb_turn) : get_entry(pow.col);
		while ((li_ch = ft_put_piece(&pow.game, play,
										col_ch - 1, pow.line - 1)) == -1)
			col_ch = get_entry(pow.col);
		play = (play == 'O') ? 'X' : 'O';
		++nb_turn;
		ft_put_game(pow, col_ch);
	}
	ft_finish(check, play, pow.player);
}

int			ft_pow4(t_pow pow, char *opt)
{
	int		nb_turn_max;

	nb_turn_max = pow.line * pow.col;
	if (ft_init_game(&pow) == -1)
		return (-1);
	ft_put_game(pow, -1);
	pow.player = ft_first_player();
	if (opt && !ft_strcmp(opt, "-p2"))
		ft_multiplayer(pow, nb_turn_max);
	else if (!opt)
		ft_player_vs_i_a(pow, nb_turn_max);
	return (0);
}
