/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:31:13 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:34:55 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

int		send_cmd_bonus(char *cmd, int sock, t_env *env)
{
	if (!ft_strncmp(cmd, "lls", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		client_ls(cmd);
	else if (!ft_strncmp(cmd, "lcd", 3) && (cmd[3] == '\0' || cmd[3] == ' '))
		client_cd(cmd, env);
	else if (!ft_strncmp(cmd, "lpwd", 4) && (cmd[4] == '\0' || cmd[4] == ' '))
		client_pwd(env);
	else if (!ft_strncmp(cmd, "mget", 4) && (cmd[4] == '\0' || cmd[4] == ' '))
		mget_client(sock, cmd);
	else if (!ft_strncmp(cmd, "mput", 4) && (cmd[4] == '\0' || cmd[4] == ' '))
		mput_client(sock, cmd);
	return (0);
}
