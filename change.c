/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:57:23 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 20:03:47 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "serveur.h"

void	clear(char ***split, int i)
{
	while (i > 0 && !(*split)[i])
		i--;
	if ((*split)[i])
		(*split)[i] = NULL;
}

char	*get_arg(char **split, int len)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	tmp1 = NULL;
	while (i < len)
	{
		if (split[i])
		{
			tmp2 = tmp1;
			tmp3 = ft_strjoin(tmp2, "/");
			tmp1 = ft_strjoin(tmp3, split[i]);
			ft_strdel(&tmp3);
			ft_strdel(&tmp2);
		}
		i++;
	}
	return (tmp1);
}

void	clear_arg(char **arg)
{
	char	**tab;
	int		i;
	int		len;

	tab = ft_strsplit(*arg, '/');
	i = 0;
	len = 0;
	while (tab[len])
		len++;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], "."))
			tab[i] = NULL;
		else if (!ft_strcmp(tab[i], ".."))
		{
			tab[i] = NULL;
			clear(&tab, i);
		}
		i++;
	}
	ft_strdel(arg);
	*arg = get_arg(tab, len);
	ft_tabfree(&tab);
}

void	change_arg_ls(char **arg, t_serv *serv)
{
	char	*tmp1;
	char	*tmp2;

	if ((*arg)[0] == '/')
	{
		tmp1 = *arg;
		*arg = ft_strjoin(serv->root, tmp1);
		ft_strdel(&tmp1);
	}
	else
	{
		tmp2 = *arg;
		tmp1 = ft_strjoin("/", tmp2);
		*arg = ft_strjoin(serv->pwd, tmp1);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	clear_arg(arg);
	if (ft_strncmp(*arg, serv->root, ft_strlen(serv->root)))
	{
		ft_strdel(arg);
		*arg = ft_strdup(serv->root);
	}
}

int		change_arg_get(char **arg, t_serv *serv)
{
	char	*tmp1;
	char	*tmp2;

	if ((*arg)[0] == '/')
	{
		tmp1 = *arg;
		*arg = ft_strjoin(serv->root, tmp1);
		ft_strdel(&tmp1);
	}
	else
	{
		tmp2 = *arg;
		tmp1 = ft_strjoin("/", tmp2);
		*arg = ft_strjoin(serv->pwd, tmp1);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	clear_arg(arg);
	if (ft_strncmp(*arg, serv->root, ft_strlen(serv->root)))
		return (-1);
	return (open(*arg, O_RDONLY));
}
