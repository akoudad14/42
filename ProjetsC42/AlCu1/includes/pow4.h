/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:06:28 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/09 14:41:05 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		POW4_H
# define	POW4_H

typedef struct		s_pow
{
	int				line;
	int				col;
	char			**game;
	char			player;
	int				mode;
}					t_pow;

void	ft_put_game(t_pow pow, int col_ch);
int		ft_check_next_turn(t_pow pow, int x, int y, int flag);
int		ft_check_three(t_pow pow, int x, int y);
int		ft_check_two(t_pow pow, int x, int y, int flag);
int		ft_verif_parameters(char *line, char *col, t_pow *pow);
int		get_entry(int col);
int		ft_verif_is_number(char *s);
char	ft_first_player(void);
int		ft_put_piece(char ***game, char piece, int col, int line_max);
int		ft_check_alignment(t_pow p, int i, int j);
int		ft_virtual_play(t_pow pow, int nb_turn);
int		ft_c_q(char p1, char p2, char p3, char p4);
int		ft_pow4(t_pow pow, char *opt);
int		ft_init_game(t_pow *pow);

#endif		/* !POW4_H */
