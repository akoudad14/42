/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:53:48 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 15:02:26 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int		ft_c_exe(char *str, char c)
{
	int		i;

	i = 0;
	if (*(str + i) == c && *(str + i + 1) == '\0')
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
	ft_putendl_fd(": No such file or directory or permission denied", 2);
	return (0);
}

void			ft_env(char *line, char **env)
{
	int		i;
	char	**tab;

	i = -1;
	tab = ft_strsplim(line);
	while (tab[++i])
	{
		if (ft_strcmp(tab[i], "env") != 0 && ft_c_exe(tab[i], '=') == 0)
		{
			ft_free_char2(tab);
			return ;
		}
	}
	i = -1;
	while (env[++i])
		ft_putendl_fd(env[i], 1);
	i = 0;
	while (tab[++i])
	{
		if (ft_strcmp(tab[i], "env") != 0)
			ft_putendl_fd(tab[i], 1);
	}
	ft_free_char2(tab);
}

static char		**ft_replace(char **env, char **tab, int i)
{
	char	**tmp;

	if (!(tmp = (char **)gmalloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = -1;
	while (env[++i])
		tmp[i] = (char *)c_calls("dup", (void *)env[i]);
	tmp[i] = '\0';
	gfree((void *)env);
	if (!(env = (char **)gmalloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = -1;
	while (tmp[++i])
		env[i] = (char *)c_calls("dup", (void *)tmp[i]);
	gfree((void *)tmp);
	env[i] = ft_strdup(tab[0]);
	gfree((void *)tab[0]);
	tab[0] = (char *)c_calls("dup", env[i]);
	env[i] = ft_strjoin(tab[0], tab[1]);
	env[i + 1] = '\0';
	gfree((void *)tab[0]);
	gfree((void *)tab[1]);
	gfree((void *)tab);
	return (env);
}

char			**ft_setenv(char *line, char **env)
{
	int		i;
	char	**tab;
	int		size;

	i = 0;
	tab = ft_strsplim(line);
	while (tab[i])
		++i;
	if (i != 2)
	{
		ft_putendl_fd("Problem arg setenv", 2);
		ft_free_char2(tab);
		return (env);
	}
	i = -1;
	tab[0] = ft_strjoin(tab[0], "=");
	size = ft_strlen(tab[0]);
	while (env[++i] && ft_strncmp(env[i], tab[0], size))
		;
	if (!env[i])
		return (env = ft_replace(env, tab, i));
	ft_strcpy(&env[i][size], tab[1]);
	ft_free_char2(tab);
	return (env);
}

char			**ft_unsetenv(char *line, char **env)
{
	int		i;
	char	**tab;

	tab = ft_strsplim(line);
	i = ft_char2_len(tab);
	if (i != 1)
		return (env + 0 * (write(2, "Problem arg unsetenv\n", 21)
							+ ft_free_char2(tab)));
	i = -1;
	tab[0] = ft_strjoin((char *)c_calls("dup", tab[0]), "=");
	while (env[++i])
	{
		if (ft_strncmp(env[i], tab[0], ft_strlen(tab[0])) == 0)
		{
			while (env[i + 1])
			{
				env[i] = (char *)c_calls("dup", (void *)env[i + 1]);
				++i;
			}
			env[i] = '\0';
			return (env + ft_free_char2(tab));
		}
	}
	return (env + 0 * (write(2, "Problem name unsetenv\n", 22)
						+ ft_free_char2(tab)));
}
