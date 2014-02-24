/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:03:48 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 14:34:12 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "sh3.h"
#include "libft.h"

static int			ft_creat(char *file)
{
	int		fd;

	if ((fd = open(file, O_APPEND | O_WRONLY)) == -1)
		return (0);
	return (fd);
}

static int			ft_right_simple(t_env *e, char **ts)
{
	pid_t	father;
	int		out;

	if ((out = open(ts[1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (write(2, "open impossible\n", 16));
	father = fork();
	if (father > 0)
		wait(&father);
	else
	{
		dup2(out, 1);
		ft_check(ts[0], e, 0);
		close(out);
		exit(1);
	}
	return (1);
}

int					ft_right(char *line, t_env *e)
{
	int		out;
	char	**ts;
	pid_t	father;
	int		i;

	i = -1;
	ts = ft_strsplit(line, '>');
	while (ts[++i])
		ts[i] = (char *)c_calls("trim", ts[i]);
	if (ft_find(line, ">>") && (out = ft_creat(ts[1])))
	{
		if ((father = fork()) > 0)
			wait(&father);
		else
		{
			dup2(out, 1);
			ft_check(ts[0], e, 0);
			exit(1);
		}
		close(out);
	}
	else
		ft_right_simple(e, ts);
	ft_free_char2(ts);
	return (1);
}
