/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:13:02 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/16 19:37:37 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "libft.h"
#include "serveur.h"

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
	ft_putstr("SUCCESS: Connexion\n");
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

int		check_mark(char *buf, int ret, char *mark)
{
	int		i;

	i = MARK_LEN;
	while (ret >= 0 && i >= 0 && buf[ret] == mark[i])
	{
		i--;
		ret--;
	}
	if (i == -1)
		return (1);
	return (0);
}

int		get_list(int sock, char *cmd)
{
	int		ret;
	char	buf[BUFF_LEN + 1];
	int		flag;

	flag = 0;
	send(sock, cmd, ft_strlen(cmd), 0);
	while ((ret = recv(sock, buf, BUFF_LEN, 0)))
	{
		buf[ret] = '\0';
		if (check_mark(buf, ret, END_MARK))
		{
			ret -= MARK_LEN;
			flag++;
		}
		write(1, buf, ret);
		if (flag)
			return (0);
	}
	return (0);
}

int		change_dir(int sock, char *cmd)
{
	send(sock, cmd, ft_strlen(cmd), 0);
	return (0);
}

int		quit_client(int sock, char *cmd)
{
	char	buf[BUFF_LEN + 1];
	int		ret;

	ret = 0;
	send(sock, cmd, ft_strlen(cmd), 0);
	ret = recv(sock, buf, BUFF_LEN, 0);
	write(1, buf, ret);
	exit(0);
	return (0);
}

int		print_path(int sock, char *cmd)
{
	int		ret;
	char	buf[BUFF_LEN + 1];

	ret = 0;
	send(sock, cmd, ft_strlen(cmd), 0);
	ret = recv(sock, buf, BUFF_LEN, 0);
	write(1, buf, ret);
	write(1, "\n", 1);
	return (0);
}

int		send_cmd(char *cmd, int sock)
{
//	char	*cmd_2;
	while (ft_isspace(*cmd))
		cmd++;
	if (*cmd == '\0')
		return (0);
//	cmd_2 = ft_strtrim(cmd);
	if (!ft_strncmp(cmd, "ls", 2))
		get_list(sock, cmd);
	else if (!ft_strncmp(cmd, "cd", 2))
		change_dir(sock, cmd);
	else if (!ft_strncmp(cmd, "pwd", 3))
		print_path(sock, cmd);
	else if (!ft_strncmp(cmd, "quit", 4))
		quit_client(sock, cmd);
/*	else if (ft_strequ(cmd, "get"))
		get_file(cmd);
	else if (ft_strequ(cmd, "put"))
	put_file(cmd);*/
//	if ((send(sock, cmd, ft_strlen(cmd), 0)) == -1)
//		ft_putstr("yolo\n");
//	free(cmd_2);
	return (0);
}

int		make_client(int sock)
{
	int		ret;
	char	buf[BUFF_LEN + 1];

	while (42)
	{
		write(1, "$> ", 3);
		ret = read(0, buf, BUFF_LEN);
		buf[ret - 1] = '\0';
		send_cmd(buf, sock);
	}
	return (0);
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
