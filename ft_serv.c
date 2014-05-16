/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:30:45 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/16 22:11:42 by mle-roy          ###   ########.fr       */
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
//	extern char		**environ;

	if ((new = (t_serv*)malloc(sizeof(t_serv))) == NULL)
		return (NULL);
	new->sock = create_server(port);
//	new->pwd = ft_getenv("PWD", environ);
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

void	check_cd(t_serv *serv)
{
	if (!ft_strncmp(serv->root, serv->pwd, ft_strlen(serv->root)))
		return ;
	else
	{
		chdir(serv->root);
		free(serv->pwd);
		serv->pwd = getcwd(NULL, 0);
	}
}

int		change_dir(t_serv *serv, char *cmd)
{
	char	**tab;
	char	*tmp;

	tab = ft_strsplit(cmd, ' ');
	if (!tab[1])
	{
		chdir(serv->root);
		free(serv->pwd);
		serv->pwd = getcwd(NULL, 0);
	}
	else
	{
		tmp = ft_strjoinwsep(serv->pwd, tab[1], '/');
		chdir(tmp);
		free(tmp);
		free(serv->pwd);
		serv->pwd = getcwd(NULL, 0);
		check_cd(serv);
	}
	return (0);
}

int		rep_list(t_serv *serv, char *cmd)
{
	char		**tmp;
	int			pid;

	tmp = ft_strsplit(cmd, ' ');
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

int		print_path(t_serv *serv, char *cmd)
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

int		quit_serv(t_serv *serv, char *cmd, int id)
{
	(void)cmd;
	printf("USER [%d] is disconnecting\n", id);
	send(serv->sock, "SUCCESS DISCONNECT\n", 19, 0);
	exit(0);
}

void	error_get(int sock)
{
	send(sock, GET_FAIL, ft_strlen(GET_FAIL), 0);
}

int		get_file(t_serv *serv, char *cmd)
{
	int		fd;
	char	**req;
	struct stat		buf;
	void	*data;

	req = ft_strsplit(cmd, ' ');
//	printf("ici1\n");
/*	if (!req[1])
	{
		error_get(serv->sock);
		return (0);
		}*/
	fd = open(req[1], O_RDONLY);
//	printf("ici1\n");
	if (fd == -1)
	{
		error_get(serv->sock);
		return (0);
	}
	send(serv->sock, GET_OK, ft_strlen(GET_OK), 0);
	fstat(fd, &buf);
	data = mmap(0, buf.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
	send(serv->sock, data, buf.st_size, 0);
	write(serv->sock, END_MARK, MARK_LEN);
	return (0);
}

int		check_mark(char *buf, int ret, char *mark)
{
	int		i;

	i = MARK_LEN - 1;
	while (ret >= 0 && i >= 0 && buf[ret - 1] == mark[i])
	{
		i--;
		ret--;
	}
	if (i == -1)
		return (1);
	return (0);
}


int		put_file(t_serv *serv, char *cmd)
{
	char	**req;
	int		fd;
	int		ret;
	char	buf[BUFF_GET + 1];
	int		flag;

	flag = 0;
	req = ft_strsplit(cmd, ' ');
	fd = open(req[1], O_WRONLY | O_CREAT, 0666);
	while ((ret = recv(serv->sock, buf, BUFF_GET, 0)))
	{
//		buf[ret] = '\0';
		if (check_mark(buf, ret, END_MARK))
		{
			ret -= MARK_LEN;
			flag++;
		}
		write(fd, buf, ret);
		if (flag)
			return (0);
	}
	return (0);
}

int		treat_req(t_serv *serv, char *cmd, int id)
{
	if (!ft_strncmp(cmd, "ls", 2) && (cmd[2] == '\0' || cmd[2] == ' '))
		rep_list(serv, cmd);
	else if (!ft_strncmp(cmd, "cd", 2) && (cmd[2] == '\0' || cmd[2] == ' '))
		change_dir(serv, cmd);
	else if (!ft_strncmp(cmd, "pwd", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		print_path(serv, cmd);
	else if (!ft_strncmp(cmd, "quit", 4) && (cmd[4] == '\0' || cmd[4] == ' '))
		quit_serv(serv, cmd, id);
	else if (!ft_strncmp(cmd, "get", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		get_file(serv, cmd);
	else if (!ft_strncmp(cmd, "put", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		put_file(serv, cmd);
/*  else if (ft_strequ(cmd, "put"))
  put_file(cmd);*/
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
