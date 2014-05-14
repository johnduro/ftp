/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistrjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:55:57 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/10 19:21:20 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_multistrjoin(size_t nb_str, ...)
{
	va_list		pa;
	char		*tmp;
	char		*str;

	if (nb_str <= 0)
		return (NULL);
	va_start(pa, nb_str);
	str = ft_strnew(0);
	while (nb_str)
	{
		tmp = str;
		str = ft_strjoin(tmp, va_arg(pa, char *));
		free(tmp);
		nb_str--;
	}
	va_end(pa);
	return (str);
}
