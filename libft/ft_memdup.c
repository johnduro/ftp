/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 18:27:01 by mle-roy           #+#    #+#             */
/*   Updated: 2013/12/10 18:31:52 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memdup(void const *s, size_t len)
{
	void	*ret;

	if (s == NULL || ((ret = malloc(len))) == NULL)
		return (NULL);
	ft_memcpy(ret, s, len);
	return (ret);
}
