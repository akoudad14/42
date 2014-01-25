/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:03:48 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 18:51:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

void				ft_free_r_l(t_r *r)
{
	ft_free_char2(r->exe);
	gfree((void *)r->path);
	gfree((void *)r);
}

static int			ft_sredirect_r(t_r *r, char **env, int i)
{
	int		out;
	pid_t	father;

	if ((out = open(r->exe[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		ft_putstr_fd(r->exe[i + 1], 2);
		ft_putendl_fd(": open impossible", 2);
		return (-1);
	}
	r->exe[i] = '\0';
	father = fork();
	if (father > 0)
	{
		wait(&father);
		close(out);
		ft_free_r_l(r);
	}
	else
	{
		dup2(out, 1);
		execve(r->path, r->exe, env);
	}
	return (1);
}

static int			ft_dredirect_r(t_r *r, char **env, int i)
{
	int		out;
	pid_t	father;

	if ((out = open(r->exe[i + 1], O_APPEND | O_WRONLY)) == -1)
	{
		ft_putstr_fd(r->exe[i + 1], 2);
		ft_putendl_fd(": open impossible", 2);
		return (-1);
	}
	r->exe[i] = '\0';
	father = fork();
	if (father > 0)
	{
		wait(&father);
		close(out);
		ft_free_r_l(r);
	}
	else
	{
		dup2(out, 1);
		execve(r->path, r->exe, env);
	}
	return (1);
}

int					ft_creat(char *file)
{
	int		fd;

	if ((fd = open(file, O_WRONLY)) == -1)
		return (1);
	close(fd);
	return (0);
}

int					ft_right(char *line, char **env)
{
	t_r		*r;
	char	*f;
	int		i;

	i = -1;
	while (ft_strncmp(env[++i], "PATH=", 5))
		;
	f = ft_strsub(env[i], 5, ft_strlen(env[i]) - 4);
	i = -1;
	if (!(r = (t_r *)gmalloc(sizeof(*r))) || !(r->exe = ft_strsplim(line)))
		return (-1);
	while (r->exe[++i])
		r->exe[i] = (char *)c_call("ft_strtrim", r->exe[i]);
	i = 0;
	while (r->exe[i][0] !=  '>')
		++i;
	if (r->exe[i + 2] != '\0')
		return (-1 + 0 * write(2, "Right: Too args\n", 16));
	if ((r->path = ft_check_exe(r->exe[0], f)) == NULL)
		return (-1 + 0 * (write(2, r->exe[0], ft_strlen(r->exe[0])
							+ write(2, ": command not found\n", 20))));
	if (ft_strncmp(r->exe[i], ">>", 2) != 0 || ft_creat(r->exe[i + 1]) == 1)
		return (0 * ft_sredirect_r(r, env, i));
	return (0 * ft_dredirect_r(r, env, i));
}
