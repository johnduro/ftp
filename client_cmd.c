/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:35:22 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:41:30 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "serveur.h"

void	client_ls(char *cmd)
{
	char	**tmp;
	int		pid;

	tmp = ft_strsplit(cmd, ' ');
	ft_strdel(&(tmp[0]));
	tmp[0] = ft_strdup("ls");
	if ((pid = fork()) == 0)
	{
		execv("/bin/ls", tmp);
		exit(-1);
	}
	wait4(pid, NULL, 0, NULL);
	ft_tabfree(&tmp);
}

void	client_pwd(t_env *env)
{
	ft_putendl(env->pwd);
}

int		mget_client(int sock, char *cmd)
{
	char	**tab;
	char	*tmp;
	int		i;

	tab = ft_strsplit(cmd, ' ');
	if (!tab[1])
		return (client_error(-4));
	i = 1;
	while (tab[i])
	{
		tmp = ft_strjoin("get ", tab[i]);
		get_client(sock, tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (0);
}

int		mput_client(int sock, char *cmd)
{
	char	**tab;
	char	*tmp;
	int		i;

	tab = ft_strsplit(cmd, ' ');
	if (!tab[1])
		return (client_error(-2));
	i = 1;
	while (tab[i])
	{
		tmp = ft_strjoin("put ", tab[i]);
		put_client(sock, tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (0);
}

void	ft_get_file(char *file, int sock)
{
	char	*tmp;
	int		fd;

	printf("SUCCESS: Receiving file: %s\n", file);
	tmp = file;
	if (ft_strchr(file, '/'))
		tmp = ft_strrchr(file, '/') + 1;
	fd = open(tmp, O_WRONLY | O_CREAT, 0666);
	sock_to_file(sock, fd);
	close(fd);
}
