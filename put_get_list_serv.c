/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_get_list_serv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:15:53 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 20:20:08 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "serveur.h"

int			rep_list(t_serv *serv, char *cmd)
{
	char	**tmp;
	int		pid;
	int		i;

	tmp = ft_strsplit(cmd, ' ');
	i = 1;
	while (tmp[i])
	{
		if (tmp[i][0] != '-')
			change_arg_ls(&(tmp[i]), serv);
		i++;
	}
	if ((pid = fork()) == 0)
	{
		dup2(serv->sock, 1);
		dup2(serv->sock, 2);
		close(serv->sock);
		execv("/bin/ls", tmp);
		exit(-1);
	}
	wait4(pid, NULL, 0, NULL);
	write(serv->sock, " 4 2 ", 5);
	ft_tabfree(&tmp);
	return (0);
}

int			get_file(t_serv *serv, char *cmd)
{
	int		fd;
	char	**req;

	req = ft_strsplit(cmd, ' ');
	if ((fd = change_arg_get(&(req[1]), serv)) == -1)
	{
		send(serv->sock, GET_FAIL, ft_strlen(GET_FAIL), 0);
		return (0);
	}
	send(serv->sock, GET_OK, ft_strlen(GET_OK), 0);
	file_to_sock(serv->sock, fd);
	ft_tabfree(&req);
	return (0);
}

int			put_file(t_serv *serv, char *cmd)
{
	char	**req;
	int		fd;

	req = ft_strsplit(cmd, ' ');
	fd = open(req[1], O_WRONLY | O_CREAT, 0666);
	sock_to_file(serv->sock, fd);
	return (0);
}
