/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 15:00:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/15 17:25:09 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "libft.h"

int		ft_send(int sock)
{
	char	*line;
	int		quit;

	quit = 0;
	while (quit == 0)
	{
		ft_putstr("$> ");
		get_next_line(1, &line);
		write(sock, line, ft_strlen(line));
		write(sock, "\n", 1);
		if (ft_strcmp(line, "quit") == 0)
			quit = 1;
		gfree(line);
	}
	return (0);
}

int		create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr * )&sin, sizeof(sin)) == -1)
		return (ft_error("Connect failed", "", -1));
	return (sock);
}


int		main(int ac, char **av)
{
	int			port;
	int			sock;

	if (ac < 3)
		return (ft_error("Too few arguments", "", -1));
	if (ac > 3)
		return (ft_error("Too many arguments", "", -1));
	port = ft_atoi(av[2]);
	if ((sock = create_client(av[1], port)) == -1)
		return (-1);
	ft_send(sock);
	close(sock);
	return (0);
}
