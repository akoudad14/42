/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 19:16:22 by rkharif           #+#    #+#             */
/*   Updated: 2014/01/05 15:18:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PIPEX_H
# define	FT_PIPEX_H

# include	<sys/stat.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<signal.h>
# include	<stdlib.h>
# include	"libft.h"

typedef struct		s_p
{
	char			*path1;
	char			*path2;
}					t_p;

/*
** In file ft_check_exe.c
*/

char		*ft_check_exe_in(char **av, char **ae, int n, int i);

#endif /* !FT_PIPEX_H */
