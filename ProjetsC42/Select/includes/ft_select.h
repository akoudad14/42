/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 10:39:24 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 15:06:14 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_SELECT_H
# define	FT_SELECT_H

# define	SIZE		5
# define	DEL(buf)	(buf[0] == 127 \
						|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 \
							&& buf[3] == 126)) ? 1 : 0

# include	<termios.h>
# include	<term.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<signal.h>
# include	"libft.h"

typedef struct			s_l
{
	char				*name;
	struct s_l			*previous;
	struct s_l			*next;
	int					j;
	int					space;
	int					del;
}						t_l;

typedef struct			s_sel
{
	t_l					*list;
	struct termios		term;
}						t_sel;

/*
** In file main.c
*/

int		ft_putc(int c);

/*
** In file ft_begin_and_end_list.c
*/

t_l		*ft_lstnew_sel(char *name);
t_l		*ft_do_list(int ac, char **av, int i);
void	ft_free_list(t_l *list);
void	ft_destruct_link(t_l *del);

/*
** In file ft_space.c
*/

void	ft_space(t_l **sel, t_l **move, int ac);

/*
** In file ft_finish.c
*/

void	ft_error_termp(char *error, char *str);
void	ft_choice_end(int ac, t_sel *sel, char *buf);

/*
** In file ft_cursor.c
*/

void	ft_cursor(t_l *list, t_l *move, int ac);

/*
** In file ft_del.c
*/

int		ft_del(t_l **list, t_l **move, int ac);

/*
** In file ft_pt_func.c
*/

int		ft_putc(int c);
void	ft_sign(int sign);

#endif	/* !FT_SELECT_H */
