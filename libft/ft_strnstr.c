/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:16:30 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/21 16:43:46 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	int			c;

	i = 0;
	c = 0;
	if (s2[0] == '\0')
		return (char*)(s1);
	while (i < n && s1[i])
	{
		j = i;
		c = 0;
		while (s1[j] == s2[c] && j < n)
		{
			j++;
			c++;
			if (s2[c] == '\0')
				return (char*)(&s1[i]);
		}
		i++;
	}
	return (NULL);
}
