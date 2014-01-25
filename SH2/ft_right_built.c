/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_built.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 14:20:02 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 18:51:30 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

static void			ft_free_r_b(t_r *r)
{
	ft_free_char2(r->exe);
	gfree((void *)r);
}

static int			ft_sr_env_pwd(char *line, char *file, char **env)
{
	int		out;
	pid_t	father;

	if (!(out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (-1 + 0 * (write(2, file, ft_strlen(file))
							+ write(2, ": open impossible\n", 18)));
	father = fork();
	if (father > 0)
	{
		wait(&father);
		close(out);
		return (0);
	}
	else
	{
		dup2(out, 1);
		if (ft_strncmp(line, "env", 3) == 0)
			ft_env(line, env);
		else
			ft_pwd(line);
		exit(1);
	}
	return (1);
}

static int			ft_dr_env_pwd(char *line, char *file, char **env)
{
	int		out;
	pid_t	father;

	if (!(out = open(file, O_APPEND | O_WRONLY)) == -1)
		return (-1 + 0 * (write(2, file, ft_strlen(file))
							+ write(2, ": open impossible\n", 18)));
	father = fork();
	if (father > 0)
	{
		wait(&father);
		close(out);
		return (0);
	}
	else
	{
		dup2(out, 1);
		if (ft_strncmp(line, "env", 3) == 0)
			ft_env(line, env);
		else
			ft_pwd(line);
		exit(1);
	}
	return (1);
}

static t_env		*ft_env_pwd_right(char *l, t_r *r, int i, t_env *e)
{
	int		j;

	j = 0;
	while (*(l + j) != '>')
		++j;
	*(l + j - 1) = '\0';
	if (ft_strcmp(r->exe[i], ">") == 0 || ft_creat(r->exe[i + 1]) == 1)
		ft_sr_env_pwd(l, r->exe[i + 1], e->envc);
	else
		ft_dr_env_pwd(l, r->exe[i + 1], e->envc);
	ft_free_r_b(r);
	return (e);
}

t_env				*ft_right_built(char *line, t_env *e)
{
	int		i;
	t_r		*r;
	int		fd;

	i = 0;
	if (!(r = (t_r *)gmalloc(sizeof(*r))))
		return (e);
	if (!(r->exe = ft_strsplim(line)))
		return (e);
	while (r->exe[i][0] != '>')
		++i;
	if (!ft_strcmp("env", r->exe[0])|| !ft_strcmp("pwd", r->exe[0]))
		return (ft_env_pwd_right(line, r, i, e));
	if ((fd = open(r->exe[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (e + 0 * (write(2, r->exe[i + 1], ft_strlen(r->exe[i + 1]))
							+ write(2, ": open impossible\n", 18)));
	close(fd);
	i = 0;
	while (*(line + i) != '>')
		++i;
	*(line + i - 1) = '\0';
	e->envc = (ft_strcmp("setenv", r->exe[0]) == 0)
		? ft_setenv(line + 6, e->envc) : ft_unsetenv(line + 9, e->envc);
	ft_free_r_b(r);
	return (e);
}
