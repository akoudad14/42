/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:03:48 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 17:59:54 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include "sh2.h"
#include "libft.h"

static int			ft_creat(char *file)
{
	int		fd;

	if ((fd = open(file, O_APPEND | O_WRONLY)) == -1)
		return (0);
	return (fd);
}

static int			ft_right_simple(t_env *e, char **tab)
{
	pid_t	father;
	int		out;

	if ((out = open(tab[1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (write(2, "open impossible\n", 16));
	father = fork();
	if (father > 0)
		wait(&father);
	else
	{
		dup2(out, 1);
		ft_check(tab[0], e, 0);
		close(out);
		exit(1);
	}
	return (1);
}

int					ft_right(char *line, t_env *e)
{
	int		out;
	char	**tab;
	pid_t	father;
	int		i;

	i = -1;
	tab = ft_strsplit(line, '>');
	while (tab[++i])
		tab[i] = (char *)c_call("ft_strtrim", tab[i]);
	if (ft_find(line, ">>") && (out = ft_creat(tab[1])))
	{
		if ((father = fork()) > 0)
			wait(&father);
		else
		{
			dup2(out, 1);
			ft_check(tab[0], e, 0);
			exit(1);
		}
		close(out);
	}
	else
		ft_right_simple(e, tab);
	ft_free_char2(tab);
	return (1);
}
