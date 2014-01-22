/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:53:48 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/18 13:21:08 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int		ft_check(char *str, char c, char **tab)
{
	int		i;

	i = 0;
	if (*(str + i) == c && (*str + i) == '\0')
		return (1);
	++i;
	while (*(str + i))
	{
		if ((*(str + i) == c))
			return (1);
		++i;
	}
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);
	free((void *)tab);
	return (0);
}

void			ft_env(char *line, char **env)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "env") != 0 && ft_check(tab[i], '=', tab) == 0)
			return ;
		++i;
	}
	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		++i;
	}
	i = 1;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "env") != 0)
			ft_putendl(tab[i]);
		++i;
	}
	free((void *)tab);
}

static char		**ft_replace(char **env, char **tab, int i)
{
	char	**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		++i;
	}
	tmp[i] = '\0';
	free((void *)env);
	if (!(env = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		env[i] = ft_strdup(tmp[i]);
		++i;
	}
	free((void *)tmp);
	env[i] = ft_strjoin(tab[0], "=");
	env[i] = ft_strjoin(env[i], tab[1]);
	env[i + 1] = '\0';
	return (env);
}

char			**ft_setenv(char *line, char **env)
{
	int		i;
	char	**tab;
	int		size;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
		++i;
	if (i != 2)
	{
		ft_putendl_fd("Problem arg setenv", 2);
		return (env);
	}
	i = 0;
	size = ft_strlen(tab[0]);
	while (env[i])
	{
		if (ft_strncmp(env[i], tab[0], size) == 0)
			ft_strcpy(&env[i][size + 1], tab[1]);
		++i;
	}
	if (!(env[i]))
		env = ft_replace(env, tab, i);
	return (env);
}

char			**ft_unsetenv(char *line, char **env)
{
	int		i;
	char	**tab;

	tab = ft_strsplit(line, ' ');
	i = 0;
	while (tab[i])
		++i;
	if (i != 1)
		return (env + 0 * write(2, "Problem arg unsetenv\n", 21));
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], tab[0], ft_strlen(tab[0])) == 0)
		{
			while (env[i + 1])
			{
				env[i] = ft_strdup(env[i + 1]);
				++i;
			}
			env[i] = '\0';
			return (env);
		}
		++i;
	}
	return (env + 0 * write(2, "Problem name unsetenv\n", 22));
}
