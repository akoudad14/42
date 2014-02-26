/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:42:54 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/26 11:03:30 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "42sh.h"
#include "libft.h"

int				ft_left(char *line, t_env *e)
{
	int		in;
	pid_t	father;
	char	**exe;
	int		i;

	i = -1;
	if (!(exe = ft_strsplit(line, '<')))
		return (-1);
	while (exe[++i])
		exe[i] = (char *)c_calls("trim", exe[i]);
	if ((in = open(exe[1], O_RDONLY)) == -1)
		return (-1 + 0 * (write(2, exe[1], ft_strlen(exe[1]))
							+ write(2, ": open fail\n", 12)));
	father = fork();
	if (father > 0)
		wait(&father);
	else
	{
		dup2(in, 0);
		ft_check(exe[0], e, 0);
		exit(1);
	}
	close(in);
	ft_free_char2(exe);
	return (1);
}
