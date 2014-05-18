/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cd_quit_client.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:09:11 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:03:36 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "libft.h"
#include "serveur.h"

void	print_client(char *addr, char *port)
{
	ft_putstr("Trying to connect to ");
	ft_putstr(addr);
	ft_putstr(" trought port ");
	ft_putstr(port);
	write(1, "\n", 1);
}

int		change_dir(int sock, char *cmd)
{
	char	buf[BUFF_LEN + 1];
	int		ret;

	ret = 0;
	send(sock, cmd, ft_strlen(cmd), 0);
	ret = recv(sock, buf, BUFF_LEN, 0);
	write(1, buf, ret);
	write(1, "\n", 1);
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
