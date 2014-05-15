/* ************************************************************************** */
/* 																			  */
/*
/* client.c
/* By: mle-roy <mle-roy@student.42.fr>
/*
/* Created: 2014/05/13 19:18:42 by mle-roy
/* Updated: 2014/05/13 19:18:44 by mle-roy
/*
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "libft.h"


int		client_error(int code)
{
	if (code == -1)
		ft_putstr("Usage ./client <addr> <port>\n");
	return (code);
}

int		create_client(char *addr, int port)
{
	int						sock;
	struct protoent			*proto;
	struct sockaddr_in		sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto );
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr_fd("ERROR: Connexion\n", 2);
		return (-1);
	}
	ft_putstr("SUCCESS: Connexion");
	return (sock);
}

void	print_client(char *addr, char *port)
{
	ft_putstr("Trying to connect to ");
	ft_putstr(addr);
	ft_putstr(" trought port ");
	ft_putstr(port);
	write(1, "\n", 1);
}

int		send_cmd(char *cmd, int sock)
{
	send(sock, cmd, ft_strlen(cmd));
}

int		make_client(int sock)
{
	int		ret;
	char	buf[BUFF_LEN];

	while (42)
	{
		write(1, "$> ", 3);
		ret = read(0, buf, BUFF_LEN + 1);
		buf[ret] = '\0';
		send_cmd(buf, sock);
	}
}

int		main(int ac, char **av)
{
	int		port;
	int		sock;

	if (ac != 3)
		return (client_error(-1));
	print_client(av[1], av[2]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	if (sock == -1)
		return (-1);
	make_client(sock);
	return (0);
}
