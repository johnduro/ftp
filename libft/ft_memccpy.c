/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:08:05 by mle-roy           #+#    #+#             */
/*   Updated: 2013/11/23 16:19:32 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	char			*s_1;
	const char		*s_2;
	unsigned char	c_;

	i = 0;
	s_1 = s1;
	s_2 = s2;
	c_ = c;
	while (i < n)
	{
		s_1[i] = s_2[i];
		if (s_2[i] == c_)
			return (&s_1[i + 1]);
		i++;
	}
	return (NULL);
}
