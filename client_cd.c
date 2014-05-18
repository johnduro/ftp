/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:35:08 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:41:06 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "serveur.h"

void	ft_cderror(int i)
{
	if (i == 1)
		ft_putendl_fd("Home not found in env", 2);
	if (i == 2)
		ft_putendl_fd("History not valid in env", 2);
	if (i == 3)
		ft_putendl_fd("cd : No such directory", 2);
}

void	ft_absolution(t_env *env, char **cmd)
{
	char	*tmp;

	tmp = ft_strjoin("/", cmd[1]);
	if (cmd[1][0] == '~')
	{
		ft_strdel(&(cmd[1]));
		cmd[1] = ft_strjoin(env->home, tmp);
		ft_strdel(&tmp);
	}
	if (cmd[1][0] != '/')
	{
		ft_strdel(&(cmd[1]));
		cmd[1] = ft_strjoin(env->pwd, tmp);
		ft_strdel(&tmp);
	}
	ft_strdel(&tmp);
	if (chdir(cmd[1]) == -1)
		return (ft_cderror(3));
	free(env->old);
	env->old = ft_strdup(env->pwd);
	free(env->pwd);
	env->pwd = getcwd(NULL, 0);
}

void	ft_cd_history(t_env *env)
{
	char	*temp;

	if (chdir(env->old) == -1)
		return (ft_cderror(2));
	temp = ft_strdup(env->old);
	free(env->old);
	env->old = ft_strdup(env->pwd);
	free(env->pwd);
	env->pwd = temp;
}

void	ft_cd_home(t_env *env)
{
	if (chdir(env->home) == -1)
		return (ft_cderror(1));
	free(env->old);
	env->old = ft_strdup(env->pwd);
	free(env->pwd);
	env->pwd = ft_strdup(env->home);
}

void	client_cd(char *cmd, t_env *env)
{
	char	**tab;

	tab = ft_strsplit(cmd, ' ');
	if (!tab[1])
		ft_cd_home(env);
	else if (ft_strcmp(tab[1], "--") == 0)
		ft_cd_home(env);
	else if (ft_strcmp(tab[1], "-") == 0)
		ft_cd_history(env);
	else
		ft_absolution(env, tab);
	ft_tabfree(&tab);
}
