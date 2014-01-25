/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 09:19:09 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 15:22:28 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

static char		*ft_good_part(char *line, int n)
{
	char	*part;
	int		i;

	i = 0;
	if (n < 0)
		return (NULL);
	if (!(part = (char *)gmalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i <= n)
	{
		*(part + i) = *(line + i);
		++i;
	}
	*(part + i) = '\0';
	return (part);
}

static int		ft_what_part(char *line)
{
	int		i;

	i = 0;
	while (*(line + i) != '<' && *(line + i) != '>')
		++i;
	i += 2;
	if (!*(line + i))
		return (-1);
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

static t_env	*ft_check_spe_next(char *line, t_env *e)
{
	int		i;

	i = 0;
	if (ft_find(line, "<") || ft_find(line, "<<"))
	{
		while (*(line + i) != '<')
			++i;
		*(line + i - 1) = '\0';
	}
	if (ft_strncmp(line, "pwd", 3) == 0
		&& (*(line + 3) == ' ' || *(line + 3) == '\0'))
		ft_env(line, e->envc);
	else if (ft_strncmp(line, "setenv", 6) == 0 && *(line + 6) == ' ')
		e->envc = ft_setenv(line + 6, e->envc);
	else if (ft_strncmp(line, "unsetenv", 8) == 0 && *(line + 8) == ' ')
		e->envc = ft_unsetenv(line + 9, e->envc);
	else if (line)
		ft_executable(line, e->env);
	return (e);
}

t_env			*ft_check_special(char *line, t_env *e, int n)
{
	int		i;
	char	*part;

	while (n-- && line)
	{
		i = ft_what_part(line);
		if (!(part = ft_good_part(line, i)))
			return (e);
		if ((ft_find(part, ">") || ft_find(part, ">>"))
			&& ft_check_built(part) == 0)
			ft_right(part, e->env);
		else if (ft_find(part, ">") || ft_find(part, ">>"))
			e = ft_right_built(part, e);
		else if (ft_find(part, "<") || ft_find(part, "<<"))
		{
			if ((i = ft_left(part, e->env)) == 1)
				e = ft_check_spe_next(part, e);
		}
		else
			e = ft_check_spe_next(part, e);
		line = ft_new_line(ft_strdup(line));
		gfree((void *)part);
	}
	return (e);
}
