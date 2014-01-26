/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:27:26 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 23:22:55 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh2.h"

char			**ft_copy_tab_tab(char **tab)
{
	char	**tabc;
	int		i;

	i = 0;
	while (tab[i] && tab[i][0])
		i++;
	if (!(tabc = (char **)gmalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (tab[i] && tab[i][0])
	{
		if (!(tabc[i] = (char *)gmalloc(sizeof(char)
										* (ft_strlen(tab[i]) + 1))))
			return (NULL);
		ft_strcpy(tabc[i], tab[i]);
		i++;
	}
	tabc[i] = '\0';
	return (tabc);
}

int				ft_check_built(char *line)
{
	if (ft_strncmp(line, "pwd", 3) == 0
		|| ft_strncmp(line, "env", 3) == 0
		|| ft_strncmp(line, "setenv", 6) == 0
		|| ft_strncmp(line, "unsetenv", 8) == 0)
		return (1);
	return (0);
}

int				ft_check_spe(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(line + j))
	{
		if (ft_strncmp(line + j, ">", 1) == 0
			|| ft_strncmp(line + j, ">>", 2) == 0
			|| ft_strncmp(line + j, "<", 1) == 0
			|| ft_strncmp(line + j, "<<", 2) == 0)
			i += 1;
		++j;
	}
	return (i);
}

void			ft_check(char *line, t_env *e, int i)
{
	if (ft_find(line, "|"))
		ft_pipe(line, e);
	else if (line[0] == '<' || line[0] == '>')
		ft_direct(line, e);
	else if (ft_strncmp(line, "cd", 2) == 0
			&& (*(line + 2) == ' ' || *(line + 2) == '\0'
				|| *(line + 2) == '\t'))
		e = ft_cd(line + 3, e);
	else if (i)
		e = ft_check_special(line, e, i);
	else if (ft_strncmp(line, "pwd", 3) == 0
		&& (*(line + 3) == ' ' || *(line + 3) == '\0'
			|| *(line + 3) == '\t'))
		ft_pwd(line);
	else if (ft_strncmp(line, "env", 3) == 0
			&& (*(line + 3) == ' ' || *(line + 3) == '\0'
				|| *(line + 3) == '\t'))
		ft_env(line, e->envc);
	else if (ft_strncmp(line, "setenv", 6) == 0 && *(line + 6) == ' ')
		e->envc = ft_setenv(line + 6, e->envc);
	else if (ft_strncmp(line, "unsetenv", 8) == 0)
		e->envc = ft_unsetenv(line + 9, e->envc);
	else if (line)
		ft_executable(line, e->env);
}

int				main(int ac, char **av, char **env)
{
	char	*l;
	t_env	e;
	char	**exe;
	int		i;
	int		j;

	j = ft_init(&e, env);
	while (j != -2 && (i = -1) == -1 && get_next_line(0, &l))
	{
		exe = ft_strsplit(l, ';');
		while (j != 1 && exe[++i] && (av = NULL) == NULL && ac > 0)
		{
			exe[i] = (char *)c_call("ft_strtrim", exe[i]);
			if (ft_strncmp(exe[i], "", 1) != 0 && !(j = ft_check_exit(exe[i])))
				ft_check(exe[i], &e, ft_check_spe(exe[i]));
		}
		gfree(l);
		if (j == 1)
			return (ft_exit(exe[i]));
		ft_free_char2(exe);
		ft_putstr("42makoudad$> ");
	}
	cfree();
	return (0);
}
