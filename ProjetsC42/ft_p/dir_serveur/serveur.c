/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 15:00:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/15 19:26:16 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "serveur.h"
#include "libft.h"

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		return (ft_error("Sock failed", "", -1));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (ft_error("Bind failed", "", -1));
	if (listen(sock, 42) == -1)
		return (ft_error("Listen failed", "", -1));
	return (sock);
}

int		ft_exe(char *str, char **path)
{
	char	**tab;
	char	*tmp;

	tab = NULL;
	tmp = NULL;
	tab = ft_strsplit(str, ' ');
	if (ft_strcmp(str, "ls") == 0)
	{
		ft_putendl("\nls:");
		ft_ls(*path);
	}
	else if (ft_strcmp(tab[0], "cd") == 0)
	{
		ft_putendl("\ncd");
		if (!tab[1])
			*path = ft_strdup("/");
		else if (ft_strcmp(tab[1], "..") == 0 && ft_strcmp(*path, "/") == 0)
			ft_cd(".");
		else if (ft_strcmp(tab[1], "..") == 0)
			ft_back(tab[1], path);
		else
		{
			if (ft_cd(tab[1]) == 0)
			{
				tmp = ft_strjoin(*path, tab[1]);
				*path = (char *)c_calld("join", tmp, "/");
				gfree(tmp);
			}
		}
	}/*
	else if (ft_strncmp(str, "get ", 4) == 0)
		ft_get_file();
	else if (ft_strncmp(str, "put ", 4) == 0)
	ft_put_file();*/
	else if (ft_strcmp(str, "pwd") == 0)
	{
		ft_putendl("\npwd:");
		ft_putendl(*path);
	}
	else if (ft_strcmp(str, "quit") == 0)
		return (-1);
	ft_free_char2(tab);
	return (0);
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	int					cslen;
	struct sockaddr_in	csin;
	char				*line;
	int					quit;
	char				*path;

	if (ac < 2)
		return (ft_error("Too few arguments", "", -1));
	if (ac > 2)
		return (ft_error("Too many arguments", "", -1));
	path = "/";
	port = ft_atoi(av[1]);
	quit = 0;
	if ((sock = create_server(port)) == -1)
		return (-1);
	cs = accept(sock, (struct sockaddr *)&csin, (socklen_t *)&cslen);
	while (!quit)
	{
		get_next_line(cs, &line);
		if (ft_exe(line, &path) == -1)
		{
			quit = 1;
			ft_putendl("\nquit");
		}
		gfree(line);
	}
	close(cs);
	close(sock);
	cfree();
	return (0);
}
