/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 17:41:09 by mle-roy           #+#    #+#             */
/*   Updated: 2013/12/06 16:00:38 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char		*s2;
	size_t		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	if ((s2 = (char *)(malloc(sizeof(*s2) * (n + 1)))) == NULL)
		return (NULL);
	while (++i < n)
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}
