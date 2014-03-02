/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:27:26 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/02 11:21:20 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"
#include "libft.h"

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
		e = ft_cd(line, e);
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

int				ft_treatment_of_the_line(t_env *e, char **exe)
{
	int		exit;
	int		i;

	exit = 0;
	i = -1;
	while (exe && exe[++i] && exit <= 0)
	{
		exe[i] = (char *)c_calls("trim", exe[i]);
		if (ft_strncmp(exe[i], "", 1) != 0
			&& !(exit = ft_check_exit(exe[i])))
			ft_check(exe[i], e, ft_check_spe(exe[i]));
	}
	return (exit);
}

static int		ft_find_the_line(t_env e)
{
	char	*line;
	int		exit;
	t_hl	*hlist;
	t_tree	*t;
	int		i;
	t_p		*p;

	line = NULL;
	hlist = NULL;
	t = NULL;
	exit = 0;
	while (exit <= 0)
	{
		ft_putstr_fd("_$> ", 1);
		i = 0;
		p = NULL;
		if ((i = ft_save_line(&hlist, &line, hlist)) == -2)
			return (-1);
		if (i == 0 && line[0] != '\0')
			i = ft_lexical_analyzer(line, &p);
		if (i == 0 && line[0] != '\0')
			i = ft_init_tree(&t);
		if (i == 0 && line[0] != '\0')
			i = ft_p_list_sub(&(t->p), p, NULL);
		if (i == 0 && t && t->p && line[0] != '\0')
			i = ft_syntaxical_analyzer(&t);
		if (i == 0 && t)
		{
/*			exe = ft_strsplit(line, ';');
			exit = ft_treatment_of_the_line(&e, exe);
			ft_free_char2(exe);*/
			ft_execute_all(t, &e);
			ft_free_tree(&t);
		}
		t = NULL;
	}
	exit -= 1;
	return (exit);
}

static int		ft_init_basic_env(char ***env)
{
	char	*buf;

	if (!(*env = (char **)gmalloc(sizeof(char *) * 4)))
		return (-1);
	buf = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	(*env)[0] = ft_strjoin(buf, ":/opt/X11/bin:/usr/texbin");
	gfree(buf);
	(*env)[1] = ft_strdup("HOME=/nfs/zfs-student-3/users/2013/");
	buf = NULL;
	buf = getcwd(buf, 0);
	(*env)[2] = ft_strjoin("PWD=", buf);
	free(buf);
	buf = NULL;
	buf = getcwd(buf, 0);
	(*env)[3] = ft_strjoin("OLDPWD=", buf);
	free(buf);
	(*env)[4] = NULL;
	return (0);
}

int				main(int ac, char **av, char **env)
{
	t_env				e;
	int					exit;
	struct termios		tattr;

	if (ac != 1 || av == NULL)
		return (-1);
	exit = 0;
	if (!ft_check_env_and_signal(env))
		return (-1);
	if (!(e.envc = ft_copy_ts(env))
		|| !(e.env = ft_copy_ts(env)))
	{
		cfree();
		return (-1);
	}
	if (!(e.env = ft_copy_ts(env)) || (ft_init_basic_env(&(e.env_s)) == -1))
	{
		cfree();
		return (-1);
	}
	if (ft_init_terminal_mode(tattr) != -1)
		exit = ft_find_the_line(e);
	cfree();
	return (exit);
}
