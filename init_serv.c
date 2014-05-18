/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:32:15 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 18:55:17 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "serveur.h"
#include "libft.h"

static int		create_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Bind error\n");
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}

t_serv			*init_serv(int port)
{
	t_serv					*new;

	if ((new = (t_serv*)malloc(sizeof(t_serv))) == NULL)
		return (NULL);
	new->sock = create_server(port);
	new->pwd = getcwd(NULL, 0);
	if (new->sock == -1 || new->pwd == NULL)
	{
		if (new->pwd)
			free(new->pwd);
		free(new);
		return (NULL);
	}
	new->root = ft_strdup(new->pwd);
	return (new);
}
