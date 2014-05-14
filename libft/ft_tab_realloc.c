/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:17:59 by mle-roy           #+#    #+#             */
/*   Updated: 2014/01/14 13:12:47 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_tab_realloc(char ***tab, char *str)
{
	int		i;
	char	**new;

	i = 0;
	while ((*tab)[i])
		i++;
	if ((new = (char **)(malloc(sizeof(char *) * (i + 2)))) == NULL)
		return (-1);
	i = 0;
	while ((*tab)[i])
	{
		if ((new[i] = ft_strdup((*tab)[i])) == NULL)
		{
			ft_tabfree(&new);
			return (-1);
		}
		i++;
	}
	new[i++] = ft_strdup(str);
	new[i] = '\0';
	ft_tabfree(tab);
	*tab = new;
	return (0);
}
