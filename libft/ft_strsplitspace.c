/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:51:52 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/21 16:45:30 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t		until_space(char const *s)
{
	size_t		ret;

	ret = 0;
	while (*s && !ft_isspace(*s))
	{
		ret++;
		s++;
	}
	return (ret);
}

static char			**space_splitting(char const *s, char **tab)
{
	size_t		i;
	int			x;
	int			len;

	i = 0;
	x = 0;
	len = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			len = until_space(&s[i]);
			tab[x++] = ft_strsub(s, i, len);
			i += len;
		}
		else
			i++;
	}
	return (tab);
}

char				**ft_strsplitspace(char const *s)
{
	int			i;
	int			t;
	char		**tab;

	i = 0;
	t = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && ((i != 0 && ft_isspace(s[i - 1])) || i == 0))
			t++;
		i++;
	}
	if ((tab = (char **)(malloc(sizeof(*tab) * (t + 1)))) == NULL)
		return (NULL);
	while (t != -1)
		tab[t--] = '\0';
	tab = space_splitting(s, tab);
	return (tab);
}
