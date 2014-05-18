/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_get_client.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 17:56:52 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:56:23 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "serveur.h"

int			get_list(int sock, char *cmd)
{
	send(sock, cmd, ft_strlen(cmd), 0);
	sock_to_file(sock, 1);
	return (0);
}

int			get_client(int sock, char *cmd)
{
	char	**tab;
	int		ret;
	char	buf[BUFF_LEN + 1];

	tab = ft_strsplit(cmd, ' ');
	if (!tab[1])
		return (client_error(-4));
	send(sock, cmd, ft_strlen(cmd), 0);
	ret = recv(sock, buf, BUFF_LEN, 0);
	buf[ret] = '\0';
	if (!ft_strcmp(GET_FAIL, buf))
	{
		printf("ERROR: You failed to receive the file: %s\n", tab[1]);
		return (0);
	}
	else if (!ft_strcmp(GET_OK, buf))
		ft_get_file(tab[1], sock);
	ft_tabfree(&tab);
	return (0);
}

int			put_client(int sock, char *cmd)
{
	char	**tab;
	int		fd;

	tab = ft_strsplit(cmd, ' ');
	if (!tab[1])
		return (client_error(-2));
	fd = open(tab[1], O_RDONLY);
	if (fd == -1)
		return (client_error(-3));
	send(sock, cmd, ft_strlen(cmd), 0);
	file_to_sock(sock, fd);
	printf("SUCCESS: file %s has been sent to server\n", tab[1]);
	ft_tabfree(&tab);
	return (0);
}
