/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 18:45:56 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/08 21:37:10 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SERVEUR_H
# define	SERVEUR_H

typedef struct		s_help
{
	char			str_pid[32];
	char			str_len[32];
	char			one_byte[8];
}					t_help;

/*
** ft_bin_to_*
*/

void		ft_bin_to_str(int *nb_bit, char **str, t_help *help);
int			ft_bin_to_len(t_help *help);
void		ft_bin_to_pid(t_help *help);

/*
** singleton_*
*/

int			*singleton_len(void);
int			*singleton_pid(void);

#endif		/* !SERVEUR_H */
