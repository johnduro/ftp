/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:39:13 by mle-roy           #+#    #+#             */
/*   Updated: 2013/11/25 17:20:52 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned int	i;
	char			*s2;
	unsigned char	c2;

	s2 = s;
	c2 = c;
	i = 0;
	while (i < len)
	{
		s2[i] = c2;
		i++;
	}
	return (s);
}
