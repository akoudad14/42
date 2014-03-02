/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 11:40:58 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/02 15:41:27 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "42sh.h"

char		**ft_create_the_line_of_cmd(t_tree *t)
{
	t_p		*move;
	char	*line_of_cmd;

	line_of_cmd = ft_strdup(t->p->tok);
	move = t->p->next;
	while (move)
	{
		line_of_cmd = c_calld("join", line_of_cmd, " ");
		line_of_cmd = c_calld("join", line_of_cmd, move->tok);
		move = move->next;
	}
	return (ft_strsplit(line_of_cmd, ' '));
}

int			ft_exe_the_cmd(t_tree *t, char *path, char **env)
{
	char	**line_of_cmd;
	pid_t	father;

	line_of_cmd = ft_create_the_line_of_cmd(t);
	*ft_value() = 0;
	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (*ft_value());
	}
	else
	{
		execve(path, line_of_cmd, env);
		ft_putstr_fd(t->p->tok, 2);
		ft_putendl_fd(": Command not found", 2);
		*ft_value() = -1;
		exit(1);
	}
	return (*ft_value());
}

char		*ft_not_need_variable_env_path(char *cmd)
{
	struct stat		*buf;

	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (NULL);
	if (lstat(cmd, buf) == 0 && buf->st_mode & S_IXUSR)
	{
		gfree(buf);
		return (cmd);
	}
	gfree(buf);
	return (NULL);
}

char		*ft_find_the_path(char *cmd, char **paths)
{
	char			*good_path;
	struct stat		*buf;
	int				i;

	good_path = NULL;
	buf = NULL;
	if ((good_path = ft_not_need_variable_env_path(cmd)))
		return (good_path);
	i = -1;
	while (paths[++i])
	{
		if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
			return (NULL);
		good_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (lstat(good_path, buf) == 0 && buf->st_mode & S_IXUSR)
		{
			gfree(buf);
			return (good_path);
		}
		gfree(good_path);
		gfree(buf);
	}
	return (NULL);
}

int			ft_perform_exe(t_tree *t, t_env *e)
{
	char	**paths;
	char	*good_path;
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (e->env[i] && ft_strncmp(e->env[i], "PATH=", 5))
		++i;
	if (!e->env[i])
		paths = ft_strsplit(&(e->env_s[0][5]), ':');
	else
		paths = ft_strsplit(&(e->env[i][5]), ':');
	if (!(good_path = ft_find_the_path(t->p->tok, paths)))
	{
		ft_free_char2(paths);
		return (ft_error_msg(t->p->tok, ": Command not found"));
	}
	value = e->env[i] ? ft_exe_the_cmd(t, good_path, e->env)
			: ft_exe_the_cmd(t, good_path, e->env_s);
	gfree(good_path);
	ft_free_char2(paths);
	return (value);
}

int		ft_perform_cmd(t_tree *t, t_env *e)
{
	int		value;

	value = 0;
	if (!ft_strcmp(t->p->tok, "exit"))
		value = ft_exit(t->p);
	else if (!ft_strcmp(t->p->tok, "echo"))
		ft_echo(t->p);
	else if (!(ft_strcmp(t->p->tok, "cd")))
		value = ft_cd(t->p, e);
	else if (ft_strcmp(t->p->tok, "setenv")
			&& ft_strcmp(t->p->tok, "unsetenv"))
		value = ft_perform_exe(t, e);
	else
		value = -1;
	return (value);
}
