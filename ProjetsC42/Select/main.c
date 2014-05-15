/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 14:55:27 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/01 13:19:28 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_init_buf(char *buf)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

static void		ft_action(int ac, t_sel *sel, t_l *move, int del)
{
	char	b[SIZE];

	while (1)
	{
		ft_init_buf(b);
		read(0, b, SIZE);
		if (b[0] == 27 && b[1] == 91 && b[2] == 65)
		{
			sel->list->j = (sel->list->j > 1) ? sel->list->j - 1 : ac - 1;
			ft_cursor(sel->list, (move = move->previous), ac);
		}
		else if (b[0] == 27 && b[1] == 91 && b[2] == 66)
		{
			sel->list->j = (sel->list->j < ac - 1) ? sel->list->j + 1 : 1;
			ft_cursor(sel->list, (move = move->next), ac);
		}
		else if (b[0] == 32)
			ft_space(&sel->list, &move, ac);
		else if ((del = DEL(b)) == 1 && ac > 2)
			ac = ft_del(&(sel->list), &move, ac);
		else if ((del == 1 && ac <= 2) || b[0] == 4
				|| (b[0] == 27 && b[1] == 0) || b[0] == 10)
			ft_choice_end(ac, sel, b);
	}
}

static int		ft_init(t_sel *sel, int ac)
{
	int		i;

	i = 2;
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
	tputs(tgetstr("us", NULL), 1, ft_putc);
	ft_putendl_fd(sel->list->name, 2);
	tputs(tgetstr("ue", NULL), 1, ft_putc);
	while ((sel->list = sel->list->next) && i < ac)
	{
		ft_putendl_fd(sel->list->name, 2);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		i++;
	}
	signal(SIGINT, ft_sign);
	signal(SIGQUIT, ft_sign);
	signal(SIGTSTP, ft_sign);
	ft_action(ac, sel, sel->list, 0);
	return (0);
}

int				main(int ac, char **av, char **env)
{
	char				*name_term;
	t_sel				*sel;

	if (!(sel = (t_sel *)malloc(sizeof(*sel))))
		ft_error("malloc", "sel/main/main.c");
	if (ac < 2)
		exit(1);/*		ft_error("ac", "main/main.c");*/
	if (env == NULL)
		/*ft_error("env", "main/main.c");*/exit(1);
	sel->list = ft_do_list(ac, av, 1);
	if (!(name_term = getenv("TERM")))
		ft_error_termp("getenv", "name_term/main/main.c");
	if (!(tgetent(NULL, name_term)))
		ft_error_termp("tegetent", "main/main.c");
	if (tcgetattr(0, &(sel->term)) == -1)
		ft_error_termp("tcgetattr", "main/main.c");
	sel->term.c_lflag &= ~(ICANON);
	sel->term.c_lflag &= ~(ECHO);
	sel->term.c_cc[VMIN] = 1;
	sel->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, 0, &(sel->term)) == -1)
		ft_error_termp("tcsetattr", "main/main.c");
	sel->list->j = 1;
	ft_init(sel, ac);
	return (0);
}
