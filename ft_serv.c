/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:30:45 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/14 18:16:38 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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
		ft_putstr("Issues accepting new conexions\n");
	return (code);
}

char		*ft_getenv(char *var, char **env)
{
	char	**tmp;
	char	*value;
	int		len;

	value = NULL;
	tmp = env;
	while (*tmp)
	{
		if ((ft_strnequ(*tmp, var, (len = ft_strlen(var))) == 1))
		{
			if ((*tmp)[len + 1] == '=')
				len++;
			value = ft_strdup((*tmp) + len + 1);
			return (value);
		}
		tmp++;
	}
	return (value);
}

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Bind error \n");
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}

t_serv		*init_serv(int port)
{
	t_serv			*new;
	extern char		**environ;

	if ((new = (t_serv*)malloc(sizeof(t_serv))) == NULL)
		return (NULL);
	new->sock = create_server(port);
	new->pwd = ft_getenv("PWD", environ);
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

int		ft_connect(int sock, struct sockaddr_in csin, unsigned int cslen)
{
	int		buf[BUFF_LEN];
	size_t	ret;

	(void)csin;
	(void)cslen;
	while ((ret = recv(sock, buf, BUFF_LEN - 1, 0)))
	{
		write(1, buf, ret);
	}
	return (0);
}

int		make_serv(t_serv *serv)
{
	int					c_sock;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				pid;

	while ((c_sock = accept(serv->sock, (struct sockaddr *)&csin, &cslen)))
	{
		if (c_sock == -1)
			return (serv_error(-4));
		if ((pid = fork()) == 0)
		{
			ft_connect(c_sock, csin, cslen);
			return (0);
		}
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
