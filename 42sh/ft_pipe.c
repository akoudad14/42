/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 18:21:54 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 15:05:16 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh3.h"
#include "libft.h"

static int		ft_pipe_n_n(t_env *e, char **ts)
{
	int		fd_pipe[2];
	pid_t	father;

	pipe(fd_pipe);
	father = fork();
	if (father > 0)
	{
		wait(&father);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[1]);
		ft_check(ts[1], e, ft_check_spe(ts[1]));
	}
	else
	{
		dup2(fd_pipe[1], 1);
		close(fd_pipe[0]);
		ft_check(ts[0], e, ft_check_spe(ts[0]));
	}
	return (1);
}

static int		ft_pipe_next(t_env *e, char **ts)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (0);
	}
	else
	{
		ft_pipe_n_n(e, ts);
		exit(1);
	}
	return (1);
}

int				ft_pipe(char *line, t_env *e)
{
	char	**ts;
	int		k;

	k = 0;
	if (!(ts = (char **)gmalloc(sizeof(char *) * 2)))
		return (-1);
	while (*(line + k) && *(line + k) != '|')
		++k;
	if (k == 0)
	{
		gfree((void *)ts);
		write(2, "Warning pipe: Missing file and/or command\n", 42);
		return (-1);
	}
	ts[0] = ft_strsub(line, 0, k);
	ts[0] = (char *)c_calls("trim", ts[0]);
	ts[1] = ft_strsub(line, k + 1, ft_strlen(line) - k - 1);
	ts[1] = (char *)c_calls("trim", ts[1]);
	ft_pipe_next(e, ts);
	return (0);
}
