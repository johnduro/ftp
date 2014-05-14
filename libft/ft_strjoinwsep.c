/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinwsep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:46:10 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/10 19:01:30 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinwsep(char const *s1, char const *s2, char sep)
{
	char		*str;
	size_t		s1_len;

	s1_len = ft_strlen(s1);
	str = ft_strnew(s1_len + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	str[s1_len] = sep;
	ft_strcat(str, s2);
	return (str);
}
