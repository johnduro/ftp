/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:13:02 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:34:19 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "serveur.h"

int		client_error(int code)
{
	if (code == -1)
		ft_putstr("Usage ./client <addr> <port>\n");
	if (code == -2)
		ft_putstr("ERROR: please use me right... \"put _FILE_\"\n");
	if (code == -3)
		ft_putstr("ERROR: Could not open file\n");
	if (code == -4)
		ft_putstr("ERROR: please use me right... \"get _FILE_\"\n");
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
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr_fd("ERROR: Connection\n", 2);
		return (-1);
	}
	ft_putstr("SUCCESS: Connection\n");
	return (sock);
}

int		send_cmd(char *cmd, int sock, t_env *env)
{
	while (ft_isspace(*cmd))
		cmd++;
	if (*cmd == '\0')
		return (0);
	if (!ft_strncmp(cmd, "ls", 2) && (cmd[2] == '\0' || cmd[2] == ' '))
		get_list(sock, cmd);
	else if (!ft_strncmp(cmd, "cd", 2) && (cmd[2] == '\0' || cmd[2] == ' '))
		change_dir(sock, cmd);
	else if (!ft_strncmp(cmd, "pwd", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		print_path(sock, cmd);
	else if (!ft_strncmp(cmd, "quit", 4) && (cmd[4] == '\0' || cmd[4] == ' '))
		quit_client(sock, cmd);
	else if (!ft_strncmp(cmd, "get", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		get_client(sock, cmd);
	else if (!ft_strncmp(cmd, "put", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		put_client(sock, cmd);
	else
		send_cmd_bonus(cmd, sock, env);
	return (0);
}

int		make_client(int sock)
{
	int				ret;
	char			buf[BUFF_LEN + 1];
	t_env			*env;
	extern char		**environ;

	env = ft_create_env(environ);
	while (42)
	{
		write(1, "$> ", 3);
		ret = read(0, buf, BUFF_LEN);
		buf[ret - 1] = '\0';
		send_cmd(buf, sock, env);
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
