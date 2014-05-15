/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 14:52:23 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/29 11:14:42 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"

static int		ft_execution(char *path, char **exe, char **env, struct stat *b)
{
	pid_t			father;

	gfree((void *)b);
	father = fork();
	if (father > 0)
	{
		wait(&father);
		gfree((void *)path);
		ft_free_char2(exe);
		return (0);
	}
	else
		execve(path, exe, env);
	return (1);
}

static int		ft_test_ok(char **path, int i)
{
	while (path[++i])
		gfree((void *)path[i]);
	return (gfree((void *)path));
}

static int		ft_test(char **path, char **exe, char **env)
{
	int				i;
	struct stat		*buf;
	char			*tmp;

	i = -1;
	tmp = NULL;
	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (-1);
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		gfree((void *)path[i]);
		path[i] = ft_strjoin(tmp, exe[0]);
		gfree((void *)tmp);
		if (lstat(path[i], buf) == 0 && buf->st_mode & S_IXUSR)
			break ;
		gfree((void *)buf);
		if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
			return (-1);
		gfree((void *)path[i]);
	}
	if (!path[i])
		return (0 - gfree((void *)path));
	ft_execution(path[i], exe, env, buf);
	return (ft_test_ok(path, i));
}

int				ft_executable(char *line, char **env)
{
	struct stat		*buf;
	char			*path;
	char			**paths;
	char			**exe;
	int				i;

	i = -1;
	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (-1);
	exe = ft_strsplim(line);
	while (env[++i] && ft_strncmp(env[i], "PATH=", 5))
		;
	path = env[i] ? ft_strdup(&env[i][5]) : NULL;
	paths = env[i] ? ft_strsplit(path, ':') : NULL;
	if (path && ft_test(paths, exe, env) != 1)
	{
		gfree((void *)path);
		if (lstat(exe[0], buf) == 0 && buf->st_mode & S_IXUSR)
			return (ft_execution(line, exe, env, buf));
		gfree((void *)buf);
		return (-1 + 0 * (write(2, line, ft_strlen(line))
						+ write(2, ": command not found or permission denied\n"
								, 41)));
	}
	return (0);
}
