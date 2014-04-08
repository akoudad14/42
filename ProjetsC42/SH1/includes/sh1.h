/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 19:19:49 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/29 16:08:30 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SH1_H
# define	SH1_H

# include	<sys/stat.h>
# include	<signal.h>
# include	<sys/wait.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"libft.h"

typedef struct		s_check
{
	int		i;
	int		j;
	int		k;
	char	**tmp;
	char	*path;
}					t_check;

/*
** In file ft_exe_without_env.c
*/

int			ft_executable(char *line, char **env);
void		ft_cd(char *line);
void		ft_pwd(char *line, int i);

/*
** In file main.c
*/

char		**ft_copy_tab_tab(char **tab);

/*
** In file ft_all_env.c
*/

void		ft_env(char *line, char **env);
char		**ft_setenv(char *line, char **env);
char		**ft_unsetenv(char *line, char **env);

#endif	/* !SH1_H */
