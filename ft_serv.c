/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:30:45 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:10:52 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "serveur.h"

int		serv_error(int code)
{
	if (code == -1)
		ft_putstr(USAGE);
	if (code == -2)
		ft_putstr("Could not init server\n");
	if (code == -3)
		ft_putstr("Wrong port number\n");
	if (code == -4)
		ft_putstr("Issues accepting new connection\n");
	return (code);
}

int		treat_req(t_serv *serv, char *cmd, int id)
{
	if (!ft_strncmp(cmd, "ls", 2) && (cmd[2] == '\0' || cmd[2] == ' '))
		rep_list(serv, cmd);
	else if (!ft_strncmp(cmd, "cd", 2) && (cmd[2] == '\0' || cmd[2] == ' '))
		change_dir_serv(serv, cmd);
	else if (!ft_strncmp(cmd, "pwd", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		print_path_serv(serv, cmd);
	else if (!ft_strncmp(cmd, "quit", 4) && (cmd[4] == '\0' || cmd[4] == ' '))
		quit_serv(serv, cmd, id);
	else if (!ft_strncmp(cmd, "get", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		get_file(serv, cmd);
	else if (!ft_strncmp(cmd, "put", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		put_file(serv, cmd);
	return (0);
}

int		ft_connect(t_serv *serv, int id)
{
	char		buf[BUFF_LEN + 1];
	size_t		ret;

	while ((ret = recv(serv->sock, buf, BUFF_LEN, 0)))
	{
		buf[ret] = '\0';
		write(1, "[Client: ", 9);
		ft_putnbr(id);
		write(1, "] ", 2);
		ft_putstr("RECV: ");
		write(1, buf, ret);
		write(1, "\n", 1);
		treat_req(serv, buf, id);
	}
	return (0);
}

int		make_serv(t_serv *serv)
{
	int					c_sock;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				pid;
	int					id;

	id = 1;
	while ((c_sock = accept(serv->sock, (struct sockaddr *)&csin, &cslen)))
	{
		if (c_sock == -1)
			return (serv_error(-4));
		if ((pid = fork()) == 0)
		{
			serv->sock = c_sock;
			ft_connect(serv, id);
			return (0);
		}
		id++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int			port;
	t_serv		*info;

	if (argc != 2)
		return (serv_error(-1));
	port = ft_atoi(argv[1]);
	if (port <= 1024)
		return (serv_error(-3));
	if ((info = init_serv(port)) == NULL)
		return (serv_error(-2));
	make_serv(info);
	return (0);
}
