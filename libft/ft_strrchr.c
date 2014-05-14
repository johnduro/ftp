/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:48:48 by mle-roy           #+#    #+#             */
/*   Updated: 2013/11/28 14:04:30 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	int		i;
	int		t;

	i = 0;
	t = 0;
	c1 = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			t = i;
		i++;
	}
	if (c == 0)
		return (char*)(&s[i]);
	if ((t == 0 && s[t] == c1) || t > 0)
		return (char*)(&s[t]);
	else
		return (NULL);
}
