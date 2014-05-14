/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:19:26 by mle-roy           #+#    #+#             */
/*   Updated: 2013/12/30 14:41:29 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = (char *)malloc(sizeof(newstr) * size + 1);
	if (newstr == NULL)
		return (NULL);
	while (i <= size)
	{
		newstr[i] = '\0';
		i++;
	}
	newstr[size] = '\0';
	return (newstr);
}
