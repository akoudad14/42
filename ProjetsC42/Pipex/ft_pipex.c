/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:16:07 by rkharif           #+#    #+#             */
/*   Updated: 2014/01/22 19:00:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void		ft_pipex(char **av, t_p *path, char **env, int in)
{
	int				out;
	pid_t			father;
	int				fd_pipe[2];
	char			**tab;

	ft_putendl_fd(path->path1, 2);
	ft_putendl_fd(path->path2, 2);
	if ((out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		ft_error("open", "second_file/ft_pipex/ft_pipex.c");
	pipe(fd_pipe);
	if ((father = fork()) == 0)
	{
		dup2(out, 1);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[1]);
		if (path->path2 != NULL)
		{
			tab = ft_strsplit(av[3], ' ');
			execve(path->path2, tab, env);
		}
	}
	dup2(in, 0);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[0]);
	tab = ft_strsplit(av[2], ' ');
	execve(path->path1, tab, env);
}

int				main(int ac, char **av, char **env)
{
	int				in;
	t_p				*path;

	in = 0;
	if (!(path = (t_p *)malloc(sizeof(*path))))
		ft_error("malloc", "path/main/ft_pipex.c");
	if (ac != 5)
		return (EXIT_FAILURE + 0 * write(2, "Problem arguments.\n", 19));
	if (env == NULL)
		ft_error("env", "env/main/ft_pipex.c");
	if (ft_check_exe_in(av, env, 2, 0) == NULL)
		ft_putendl_fd("First exe is a command unknown", 2);
	else
		path->path1 = ft_strdup(ft_check_exe_in(av, env, 2, 0));
	if (ft_check_exe_in(av, env, 3, 0) == NULL)
		ft_putendl_fd("Second exe is a command unknown", 2);
	else
		path->path2 = ft_strdup(ft_check_exe_in(av, env, 3, 0));
	if ((in = open(av[1], O_RDONLY)) == -1)
		ft_error("open", "first_file/main/ft_pipex.c");
	ft_pipex(av, path, env, in);
	return (1);
}
