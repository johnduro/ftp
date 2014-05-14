/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinwsep_nfree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:28:57 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/21 16:46:07 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoinwsep_nfree(char *s1, char const *s2, char const c)
{
	char	*new;

	new = ft_strjoinwsep((const char *)s1, s2, c);
	free(s1);
	return (new);
}
