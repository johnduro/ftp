/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:10:43 by mle-roy           #+#    #+#             */
/*   Updated: 2013/11/28 14:03:53 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;

	c1 = (char)c;
	while (*s)
	{
		if (*s == c1)
			return (char*)(s);
		s++;
	}
	if (*s == '\0' && c1 == '\0')
		return (char*)(s);
	else
		return (NULL);
}
