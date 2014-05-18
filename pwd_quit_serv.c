/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_quit_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:28:26 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:03:13 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

int			print_path_serv(t_serv *serv, char *cmd)
{
	int		i;

	i = 0;
	(void)cmd;
	while (serv->root[i])
		i++;
	if (serv->pwd[i] == '\0')
		send(serv->sock, "/", 1, 0);
	else
		send(serv->sock, &(serv->pwd[i]), (ft_strlen(serv->pwd) - i), 0);
	return (0);
}

int			quit_serv(t_serv *serv, char *cmd, int id)
{
	(void)cmd;
	printf("CLIENT [%d] is disconnecting\n", id);
	send(serv->sock, "SUCCESS DISCONNECT\n", 19, 0);
	exit(0);
}
