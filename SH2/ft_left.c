/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:42:54 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 18:50:32 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

static int		ft_exec(t_r *r, char **env, int i, int in)
{
	pid_t	father;

	r->exe[i] = '\0';
	father = fork();
	if (father > 0)
	{
		wait(&father);
		close(in);
		ft_free_r_l(r);
		return (0);
	}
	else
	{
		dup2(in, 0);
		execve(r->path, r->exe, env);
		exit(1);
	}
	return (1);
}

int				ft_left(char *line, char **env)
{
	t_r		*r;
	char	*fpath;
	int		i;
	int		in;

	i = 0;
	fpath = ft_strdup(&env[0][5]);
	if (!(r = (t_r *)gmalloc(sizeof(*r))))
		return (-1 + 0 * write(2, "Problem malloc t_r\n", 19));
	if (!(r->exe = ft_strsplim(line)))
		return (-1 + 0 * write(2, "Problem split left\n", 20));
	while (r->exe[i][0] != '<')
		++i;
	if ((in = open(r->exe[i + 1], O_RDONLY)) == -1)
		return (-1 + 0 * (write(2, r->exe[i + 1], ft_strlen(r->exe[i + 1]))
							+ write(2, ": open impossible\n", 18)));
	if (r->exe[i + 2] != '\0')
		return (-1 + 0 * write(2, "Right: Too args\n", 16));
	if ((r->path = ft_check_exe(r->exe[0], fpath)) == NULL)
		return (-1 + 0 * (write(2, r->exe[0], ft_strlen(r->exe[0]))
							+ write(2, ": command not found\n", 20)));
	if (ft_strcmp(r->exe[0], "cat") == 0)
		return (0 * ft_exec(r, env, i, in));
	return (1);
}
