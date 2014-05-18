/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:35:37 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 19:36:01 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "serveur.h"

t_env	*ft_create_env(char **env)
{
	int		i;
	t_env	*new;

	i = 0;
	new = (t_env *)malloc(sizeof(*new));
	if (!new)
		exit(-1);
	new->home = NULL;
	new->pwd = NULL;
	new->old = NULL;
	while (env[i] != NULL)
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
			new->pwd = ft_strdup(env[i] + 4);
		else if (!ft_strncmp(env[i], "OLDPWD=", 7))
			new->old = ft_strdup(env[i] + 7);
		else if (!ft_strncmp(env[i], "HOME=", 5))
			new->home = ft_strdup(env[i] + 5);
		i++;
	}
	return (new);
}

void	ft_del_env(t_env *env)
{
	ft_strdel(&(env->home));
	ft_strdel(&(env->pwd));
	ft_strdel(&(env->old));
	free(env);
}
