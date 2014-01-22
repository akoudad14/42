/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:27:26 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/18 13:25:55 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char			**ft_copy_tab_tab(char **tab)
{
	char	**tabc;
	int		i;

	i = 0;
	while (tab[i] && tab[i][0])
		i++;
	if (!(tabc = (char **)malloc(sizeof(char *) * i * i)))
		exit(-1);
	i = 0;
	while (tab[i] && tab[i][0])
	{
		if (!(tabc[i] = (char *)malloc(sizeof(char) * (ft_strlen(tab[i]) + 1))))
			exit(-1);
		ft_strcpy(tabc[i], tab[i]);
		i++;
	}
	tabc[i] = '\0';
	return (tabc);
}

static char		**ft_check(char *line, char **envc)
{
	if (ft_strncmp(line, "pwd", 3) == 0
		&& (*(line + 3) == ' ' || *(line + 3) == '\0'))
		ft_pwd(line, 3);
	else if (ft_strncmp(line, "cd", 2) == 0
			&& (*(line + 2) == ' ' || *(line + 2) == '\0'))
		ft_cd(line + 3);
	else if (ft_strncmp(line, "env", 3) == 0
			&& (*(line + 3) == ' ' || *(line + 3) == '\0'))
		ft_env(line, envc);
	else if (ft_strncmp(line, "setenv", 6) == 0 && *(line + 6) == ' ')
		envc = ft_setenv(line + 6, envc);
	else if (ft_strncmp(line, "unsetenv", 8) == 0)
		envc = ft_unsetenv(line + 9, envc);
	else if (line)
		ft_executable(line, envc);
	free((void *)line);
	return (envc);
}

static void		catch_sign(int sign)
{
	if (sign == SIGINT || sign == SIGQUIT || sign == SIGTSTP)
		return ;
}

int				main(int ac, char **av, char **env)
{
	char	*line;
	char	**envc;

	av = NULL;
	signal(SIGINT, catch_sign);
	signal(SIGQUIT, catch_sign);
	signal(SIGTSTP, catch_sign);
	if (!env[0])
		ft_error("env", "env/main");
	envc = ft_copy_tab_tab(env);
	ft_putstr("42makoudad$> ");
	while (get_next_line(0, &line) && ft_strcmp(line, "exit") != 0 && ac > 0)
	{
		line = ft_strtrim(line);
		if (ft_strcmp(line, "") == 0)
			ft_putstr("42makoudad$> ");
		else
		{
			envc = ft_check(line, envc);
			ft_putstr("42makoudad$> ");
		}
	}
	exit(0);
	return (0);
}
