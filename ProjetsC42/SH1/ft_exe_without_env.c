/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_without_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 19:45:13 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/18 14:15:15 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int		ft_found_or_not(char *line, char **exe, t_check *check)
{
	if (!exe[check->j])
	{
		ft_putendl(ft_strcat(line, ": command not found"));
		free((void *)exe);
		return (-1);
	}
	return (0);
}

static t_check		*exe(char *line, char **env, t_check *ck)
{
	struct stat		*buf;

	while (*(line + ck->i) && *(line + ck->i) != ' ')
		ck->i++;
	env[ck->j] = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:");
	env[ck->j] = ft_strjoin(env[ck->j], "/sbin:/opt/X11/bin:/usr/texbin");
	ck->tmp = ft_strsplit(&env[ck->j][5], ':');
	ck->j = 0;
	ck->path = ft_strsub(line, 0, ck->i);
	buf = (struct stat *)malloc(sizeof(*buf));
	if (lstat(ck->path, buf) != 0)
		ck->k = -1 ;
	free((void *)buf);
	while (ck->k == -1 && ck->tmp[ck->j])
	{
		ck->path = ft_strjoin(ck->tmp[ck->j], "/");
		ck->path = ft_strjoin(ck->path, ft_strsub(line, 0, ck->i));
		buf = (struct stat *)malloc(sizeof(*buf));
		if (lstat(ck->path, buf) == 0)
			break ;
		free((void *)buf);
		free((void *)ck->path);
		ck->j++;
	}
	return (ck);
}

int				ft_executable(char *line, char **env)
{
	pid_t			father;
	t_check			*check;

	check = (t_check *)malloc(sizeof(*check));
	check->i = 0;
	check->j = 0;
	check->k = 0;
	check = exe(line, env, check);
	if (ft_found_or_not(line, check->tmp, check) == -1)
		return (-1);
	if (check->k == -1)
		free((void *)check->tmp);
	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (0);
	}
	if (father == 0)
		execve(check->path, check->tmp = ft_strsplit(line, ' '), env);
	free((void *)check->tmp);
	free((void *)check->path);
	return (1);
}

void			ft_cd(char *line)
{
	if (chdir(line) < 0)
	{
		ft_putstr("cd: not a directory or permission denied: ");
		ft_putendl(line);
	}
}

void			ft_pwd(char *line, int i)
{
	char			*buf;

	while (*(line + i++))
	{
		if (*(line + i) != ' ')
		{
			ft_putendl("pwd: too many arguments");
			return ;
		}
	}
	if (!(buf = ft_strnew(2000)))
		ft_putendl("pwd: fail");
	ft_putendl(getcwd(buf, 2000));
	free((void *)buf);
}
