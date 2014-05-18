/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_serv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:22:22 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:46:02 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include "libft.h"
#include "serveur.h"

static int		check_cd(t_serv *serv)
{
	if (!ft_strncmp(serv->root, serv->pwd, ft_strlen(serv->root)))
		return (1);
	else
	{
		chdir(serv->root);
		free(serv->pwd);
		serv->pwd = getcwd(NULL, 0);
		send(serv->sock, CD_FAIL, ft_strlen(CD_FAIL), 0);
	}
	return (0);
}

static void		cd_to_root(t_serv *serv)
{
	chdir(serv->root);
	free(serv->pwd);
	serv->pwd = getcwd(NULL, 0);
	send(serv->sock, CD_OK, ft_strlen(CD_OK), 0);
}

int				change_dir_serv(t_serv *serv, char *cmd)
{
	char		**tab;
	char		*tmp;

	tab = ft_strsplit(cmd, ' ');
	if (!tab[1])
		cd_to_root(serv);
	else
	{
		tmp = ft_strjoinwsep(serv->pwd, tab[1], '/');
		if (chdir(tmp) == -1)
		{
			free(tmp);
			send(serv->sock, CD_FAIL, ft_strlen(CD_FAIL), 0);
			return (0);
		}
		free(tmp);
		free(serv->pwd);
		serv->pwd = getcwd(NULL, 0);
		if (check_cd(serv))
			send(serv->sock, CD_OK, ft_strlen(CD_OK), 0);
	}
	return (0);
}
