/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 18:38:01 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 18:56:34 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

static int		ft_cat_in(char **tab, t_env *e)
{
	char	*line;
	char	*tmp;
	int		i;

	i = -1;
	line = ft_strdup("cat");
	while (tab[++i])
	{
		tmp = ft_strjoin(line, " ");
		gfree((void *)line);
		line = ft_strjoin(tmp, tab[i]);
		gfree((void *)tmp);
	}
	ft_check(line, e, 0);
	gfree((void *)line);
	return (1);
}

static int		ft_cat_out(char *f, t_env *e, char *l)
{
	char	*line;

	if (!(line = (char *)gmalloc(sizeof(char)
								* (ft_strlen(f) + ft_strlen("cat >  ") + 1))))
		return (-1);
	if (ft_strncmp(l, ">>", 2) == 0)
		line = ft_strcpy(line, "cat >> ");
	else
		line = ft_strcpy(line, "cat > ");
	line = ft_strcat(line, f);
	ft_check(line, e, 1);
	gfree((void *)line);
	return (-2);
}

static char		*ft_sim_or_doub(char *line, int i)
{
	int		j;

	j = 0;
	++line;
	while (i && ++line)
	{
		if (*line == '>' && --i)
			++line;
	}
	if (ft_strncmp(line, ">>", 2) == 0)
		return (" >> ");
	else
		return (" > ");
}

static void		ft_copy(char **tab, t_env *e, int i, char *l)
{
	char	*line;
	char	*tmp;

	if (!(line = (char *)gmalloc(sizeof(char)
								* (ft_strlen(tab[0]) + ft_strlen("cat  >  ")
								+ ft_strlen(tab[i]) + 1))))
		return ;
	line = ft_strcpy(line, "cat ");
	tmp = ft_strtrim(tab[0]);
	line = ft_strcat(line, tmp);
	line = ft_strcat(line, ft_sim_or_doub(l, i + 1));
	gfree((void *)tmp);
	tmp = ft_strtrim(tab[i]);
	line = ft_strcat(line, tmp);
	gfree((void *)tmp);
	ft_check(line, e, 1);
	gfree((void *)line);
}

void			ft_direct(char *l, t_env *e)
{
	char	**tab;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tab = (l[0] == '<') ? ft_strsplit(l, '<') : ft_strsplit(l, '>');
	while (tab[++i])
	{
		if (tab[i][0] != '<' && tab[i][0] != '>')
		{
			tab[++j] = (char *)c_call("ft_strdup", tab[i]);
			tab[j] = (char *)c_call("ft_strtrim", tab[j]);
		}
	}
	if (j != -1)
	{
		i = 0;
		j = (l[0] == '<') ? ft_cat_in(tab, e) : ft_cat_out(tab[0], e, l);
		while (j == -2 && tab[++i])
			ft_copy(tab, e, i, l);
	}
	ft_free_char2(tab);
}
