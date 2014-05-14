/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:15:01 by mle-roy           #+#    #+#             */
/*   Updated: 2013/11/28 13:54:19 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s_1;
	const unsigned char		*s_2;
	unsigned int			i;

	i = 0;
	s_1 = (const unsigned char*)s1;
	s_2 = (const unsigned char*)s2;
	while (i < n)
	{
		if (s_1[i] != s_2[i])
			return (int)(s_1[i] - s_2[i]);
		i++;
	}
	return (0);
}
