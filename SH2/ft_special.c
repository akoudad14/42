/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 09:19:09 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 17:59:09 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh2.h"
#include "libft.h"

static int		ft_what_part(char *line)
{
	int		i;

	i = 0;
	while (*(line + i) != '<' && *(line + i) != '>')
		++i;
	i += 2;
	if (!*(line + i))
		return (-1 * write(2, "Missing file\n", 13));
	while (*(line + i))
	{
		if (*(line + i) == '<' || *(line + i) == '>')
			return (i -= 2);
		++i;
	}
	return (i);
}

static char		*ft_new_line(char *line)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (*(line + i) != '<' && *(line + i) != '>')
		++i;
	tmp = ft_strsub(line, 0, i);
	while (*(line + i)
			&& (*(line + i) == '<' || *(line + i) == '>' || *(line + i) == ' '))
		++i;
	while (*(line + i) && *(line + i) != '<' && *(line + i) != '>')
		++i;
	tmp2 = *(line + i) ? ft_strsub(line, i, ft_strlen(line) - i + 1) : NULL;
	gfree((void *)line);
	if (tmp2 == NULL)
	{
		gfree((void *)tmp);
		return (NULL);
	}
	line = ft_strjoin(tmp, tmp2);
	gfree((void *)tmp);
	gfree((void *)tmp2);
	return (line);
}

t_env			*ft_check_special(char *line, t_env *e, int n)
{
	int		i;
	char	*part;
	int		j;

	j = 0;
	while (n-- && line)
	{
		i = ft_what_part(line);
		if (i < 0 || !(part = ft_strsub(line, 0, i + 1)))
			return (e);
		if ((ft_find(part, ">") || ft_find(part, ">>")) && (j += 1))
			ft_right(part, e);
		else if ((ft_find(part, "<") || ft_find(part, "<<"))
				&& ((j += 1) == 1 || !ft_strncmp(part, "cat", 3)))
			ft_left(part, e);
		line = ft_new_line(ft_strdup(line));
		gfree((void *)part);
	}
	return (e);
}
