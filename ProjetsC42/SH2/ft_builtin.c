/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:47:43 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/29 11:09:54 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh2.h"
#include "libft.h"

static t_env	*ft_good_env(t_env *e, char *pwd, char *oldpwd)
{
	int		i;

	i = -1;
	while (e->env[++i] && ft_strncmp(e->env[i], "PWD=", 4))
		;
	gfree(e->env[i]);
	e->env[i] = ft_strjoin("PWD=", pwd);
	i = -1;
	while (e->env[++i] && ft_strncmp(e->env[i], "OLDPWD=", 7))
		;
	gfree(e->env[i]);
	e->env[i] = ft_strjoin("OLDPWD=", oldpwd);
	i = -1;
	while (e->envc[++i] && ft_strncmp(e->envc[i], "PWD=", 4))
		;
	gfree(e->envc[i]);
	e->envc[i] = ft_strjoin("PWD=", pwd);
	i = -1;
	while (e->envc[++i] && ft_strncmp(e->envc[i], "OLDPWD=", 7))
		;
	gfree(e->envc[i]);
	e->envc[i] = ft_strjoin("OLDPWD=", oldpwd);
	return (e);
}

static t_env	*ft_actualize(t_env *e, char *oldpwd, char **tab, int i)
{
	char	*pwd;

	pwd = (char *)gmalloc(sizeof(char) * 20000);
	getcwd(pwd, 20000);
	if (!i && tab[1] && !tab[2])
	{
		ft_putstr_fd("cd: not a directory or permission denied: ", 2);
		ft_putendl_fd(tab[1], 2);
	}
	else if (!i && tab[1] && tab[2])
		ft_putendl_fd("cd: too args", 2);
	else
		e = ft_good_env(e, pwd, oldpwd);
	ft_free_char2(tab);
	gfree(oldpwd);
	gfree(pwd);
	return (e);
}

t_env			*ft_cd(char *line, t_env *e)
{
	int		i;
	char	*buf;
	char	**t;

	t = ft_strsplim(line);
	buf = (char *)gmalloc(sizeof(char) * 20000);
	getcwd(buf, 20000);
	i = 0;
	if (t[1] && !t[2] && chdir(t[1]) >= 0)
		return (ft_actualize(e, buf, t, 1));
	if (!t[1])
	{
		while (e->env[i] && ft_strncmp(e->env[i], "HOME", 4) != 0)
			++i;
		if (e->env[i])
			chdir(&(e->env[i][5]));
	}
	else if (!ft_strcmp(t[1], "-") && !t[2])
	{
		while (e->env[i] && ft_strncmp(e->env[i], "OLDPWD", 6) != 0)
			++i;
		if (e->env[i])
			chdir(&(e->env[i][7]));
	}
	return (ft_actualize(e, buf, t, i));
}

void			ft_pwd(char *line)
{
	char	**buf;
	int		i;

	i = -1;
	if (!(buf = ft_strsplim(line)))
		return ;
	while (buf[++i])
		buf[i] = (char *)c_call("ft_strtrim", buf[i]);
	if (buf[1] != '\0')
	{
		ft_putendl_fd("pwd: too many arguments", 2);
		ft_free_char2(buf);
		return ;
	}
	if (!(buf[0] = ft_strnew(2000)))
		return ;
	ft_putendl(getcwd(buf[0], 2000));
	ft_free_char2(buf);
}
