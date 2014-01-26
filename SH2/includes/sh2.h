/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 19:19:49 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/25 23:08:34 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SH2_H
# define	SH2_H

# include	<sys/stat.h>
# include	<signal.h>
# include	<sys/wait.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"libft.h"

typedef struct		s_r
{
	char			**exe;
	char			*path;
}					t_r;

typedef struct		s_env
{
	char			**env;
	char			**envc;
}					t_env;

/*
** In file ft_init.c
*/

int			ft_init(t_env *e, char **env);

/*
** In file ft_exe.c
*/

int			ft_executable(char *line, char **env);

/*
** In file main.c
*/

void		ft_check(char *line, t_env *e, int i);
char		**ft_copy_tab_tab(char **tab);
int			ft_check_built(char *line);
int			ft_check_spe(char *line);

/*
** In file ft_special.c
*/

t_env		*ft_check_special(char *line, t_env *e, int n);

/*
** In file ft_direct.c
*/

void		ft_direct(char *line, t_env *e);

/*
** In file ft_env.c
*/

void		ft_env(char *line, char **env);
char		**ft_setenv(char *line, char **env);
char		**ft_unsetenv(char *line, char **env);

/*
** In file ft_check_env_and_signal.c
*/

int			ft_check_env_and_signal(char **env);

/*
** In file ft_right.c
*/

int			ft_right(char *line, t_env *e);
int			ft_creat(char *file);
void		ft_free_r_l(t_r *r);

/*
** In file ft_left.c
*/

int			ft_left(char *line, t_env *e);
char		*ft_new_l(char **exe, char c);

/*
** In file ft_pipe.c
*/
void		ft_pipe(char *line, t_env *e);

/*
** In file ft_check_exe.c
*/

char		*ft_check_exe(char *s, char *path);

/*
** In file ft_builtin.c
*/

t_env		*ft_cd(char *line, t_env *e);
void		ft_pwd(char *line);

/*
** In file ft_exit.c
*/

int			ft_check_exit(char *line);
int			ft_exit(char *line);

#endif	/* !SH2_H */
