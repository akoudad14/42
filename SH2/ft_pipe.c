/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 18:21:54 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/26 14:22:20 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

static int		ft_pipe_n_n(t_env *e, char **tab)
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
		ft_check(tab[1], e, ft_check_spe(tab[1]));
	}
	else
	{
		dup2(fd_pipe[1], 1);
		close(fd_pipe[0]);
		ft_check(tab[0], e, ft_check_spe(tab[0]));
	}
	return (1);
}

static int		ft_pipe_next(t_env *e, char **tab)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		gfree(tab[0]);
		gfree(tab[1]);
		gfree(tab);
		return (0);
	}
	else
	{
		ft_pipe_n_n(e, tab);
		exit(1);
	}
	return (1);
}

void			ft_pipe(char *line, t_env *e)
{
	char	**tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tab = (char **)gmalloc(sizeof(char *) * 2)))
		return ;
	while (*(line + k) && *(line + k) != '|')
		++k;
	if (k == 0)
	{
		gfree((void *)tab);
		return ;
	}
	tab[0] = ft_strsub(line, 0, k);
	tab[0] = (char *)c_call("ft_strtrim", tab[0]);
	tab[1] = ft_strsub(line, k + 1, ft_strlen(line) - k - 1);
	tab[1] = (char *)c_call("ft_strtrim", tab[1]);
	if (tab[1])
		ft_pipe_next(e, tab);
	else
		ft_free_char2(tab);
}
