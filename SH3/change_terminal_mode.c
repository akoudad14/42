/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_terminal_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 13:23:21 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 14:21:05 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh3.h"

int		ft_init_terminal_mode(struct termios tattr)
{
	char			*term_name;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return (-1);
	tattr.c_lflag &= ~(OPOST);
	tattr.c_lflag &= ~(ICANON);
	tattr.c_lflag &= ~(ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr) == -1)
		return (-1);
	return (0);
}

int		ft_default_terminal_mode(struct termios tattr)
{
	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return (-1);
	tattr.c_lflag |= ~(OPOST);
	tattr.c_lflag |= ~(ICANON);
	tattr.c_lflag |= ~(ECHO);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr) == -1)
		return (-1);
	return (0);
}
