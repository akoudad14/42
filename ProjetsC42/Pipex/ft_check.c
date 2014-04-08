/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 12:46:17 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/05 15:18:59 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static char		*ft_check_exe_out(char *exe, char **env, int i)
{
	struct stat		*buf;
	char			**cut;
	char			*path;

	path = NULL;
	cut = NULL;
	buf = NULL;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	cut = ft_strsplit(&env[i][5], ':');
	i = 0;
	while (cut[i])
	{
		path = ft_strjoin(cut[i], "/");
		path = ft_strjoin(path, exe);
		if (!(buf = (struct stat *)malloc(sizeof(*buf))))
			ft_error("malloc", "buf/ft_check/ft_check_first_exe_out");
		if (lstat(path, buf) == 0)
			return (path);
		free((void *)buf);
		free((void *)path);
		i++;
	}
	return (NULL);
}

char			*ft_check_exe_in(char **av, char **ae, int n, int i)
{
	struct stat		*buf;
	char			*path;
	int				j;

	j = 0;
	path = NULL;
	if (!(buf = (struct stat *)malloc(sizeof(*buf))))
		ft_error("malloc", "buf/ft_check/ft_check_first_exe_in");
	while (av[n][i] && av[n][i] != ' ')
		i++;
	if (!(path = (char *)malloc(sizeof(*path) * i + 1)))
		ft_error("malloc", "path/ft_check/ft_check_first_exe_in");
	while (j < i)
	{
		path[j] = av[n][j];
		j++;
	}
	path[j] = '\0';
	if (lstat(av[n], buf) == -1)
	{
		free((void *)buf);
		return (ft_check_exe_out(path, ae, 0));
	}
	free((void *)buf);
	return (path);
}
