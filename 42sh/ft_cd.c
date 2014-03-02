/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:47:33 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/02 15:46:08 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "42sh.h"
#include "libft.h"

/* La fonction ft_change_value_variable pourra surement etre reutiliser avec setenv*/
int			ft_change_value_variable(char *var, char *val, char ***env)
{
	int		i;

	i = 0;
	while (ft_strncmp((*env)[i], var, ft_strlen(var)))
		++i;
	if (!((*env)[i]))
		return (-1);
	gfree((*env)[i]);
	(*env)[i] = ft_strjoin(var, val);
	return (0);
}

int			ft_return_last_rep(t_env *e, char *old_pwd)
{
	int		i;
	char	*pwd;

	pwd = NULL;
	i = -1;
	while (e->env[i] && ft_strncmp(e->env[i], "OLDPWD=", 7))
		++i;
	if (!(e->env[i]) || (chdir(&(e->env[i][7])) == -1))
		return (ft_error_msg(": No such file or directory", ""));
	pwd = getcwd(pwd, 0);
	ft_change_value_variable("PWD=", pwd, &(e->env));
	ft_change_value_variable("PWD=", pwd, &(e->env_s));
	ft_change_value_variable("OLDPWD=", old_pwd, &(e->env));
	return (0);
}

int			ft_return_home(t_env *e, char *old_pwd)
{
	char	*pwd;
	int		i;

	pwd = NULL;
	i = -1;
	while (e->env[i] && ft_strncmp(e->env[i], "HOME=", 5))
		++i;
	if (!(e->env[i]))
		return (ft_error_msg("cd: No home directory", ""));
	if (chdir(&(e->env[i][5])) == -1)
		return (ft_error_msg("cd: Can't change to home directory", ""));
	pwd = getcwd(pwd, 0);
	ft_change_value_variable("PWD=", pwd, &(e->env));
	ft_change_value_variable("PWD=", pwd, &(e->env_s));
	ft_change_value_variable("OLDPWD=", old_pwd, &(e->env));
	return (0);
}

int			ft_go_to_rep(char *rep, t_env *e, char *old_pwd)
{
	char			*pwd;
	struct stat		*buf;
	int				value1;
	int				value2;

	pwd = NULL;
	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (-1);
	value1 = chdir(rep);
	value2 = lstat(rep, buf);
	if (value1 == -1 && value2 == 0 && buf->st_mode & S_IFDIR)
		return (ft_error_msg(rep, ": Permission denied"));
	else if (value1 == -1 && value2 == 0)
		return (ft_error_msg(rep, ": Not a directory"));
	else if (value1 == -1 && value2 == -1)
		return (ft_error_msg(rep, ": No such file or directory"));
	pwd = getcwd(pwd, 0);
	ft_change_value_variable("PWD=", pwd, &(e->env));
	ft_change_value_variable("PWD=", pwd, &(e->env_s));
	ft_change_value_variable("OLDPWD=", old_pwd, &(e->env));
	return (0);
}

int			ft_cd(t_p *p, t_env *e)
{
	int		value;
	char	*buf;

	value = 0;
	buf = NULL;
	buf = getcwd(buf, 0);
	if (!p->next)
		value = ft_return_home(e, buf);
	else if (p->next->next)
		value = ft_error_msg("cd: Too many arguments", "");
	else if (!ft_strcmp(p->tok, "-"))
		value = ft_return_last_rep(e, buf);
	else
		value = ft_go_to_rep(p->next->tok, e, buf);
	free(buf);
	return (value);
}
