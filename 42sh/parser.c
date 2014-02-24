/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:06:58 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/24 19:16:02 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh3.h"

void	ft_print_pl(t_p *p)
{
	t_p		*move;

	move = p;
	while (move)
	{
		ft_putstr(move->tok);
		ft_putstr(" ");
		ft_putnbr(move->type);
		ft_putstr("\n");
		move = move->next;
	}
}

int		ft_new_token(t_p **p, char **line, int size, int type)
{
	t_p		*new;
	t_p		*move;

	if (!(new = (t_p *)gmalloc(sizeof(t_p))))
		return (-1);
	if (!(new->tok = ft_strsub(*line, 0, size)))
		return (-1);
	*line = *line + size;
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	move = *p;
	if (*p)
	{
		while (move->next)
			move = move->next;
		new->prev = move;
		move->next = new;
	}
	else
		*p = new;
	return (0);
}

int		ft_parser(char *line)
{
	int		ind;
	t_p		*p;
	int		type;
	int		size;

	ind = 0;
	p = NULL;
	while (*line)
	{
		size = ft_word_size_before_ope(line, &ind, &type);
		if (size != 0)
			ft_new_token(&p, &line, size, WORD);
		if (!*line)
			break ;
		size = (type == AND || type == OR || type == RED_DR) ? 2 : 1;
		ft_new_token(&p, &line, size, type);
	}
	if (ft_delete_quotes_and_spaces(&p, ind) == -1)
		return (-1);
	if (ft_delete_backslashes(&p) == -1)
		return (-1);
	ft_print_pl(p);
	return (0);
}
