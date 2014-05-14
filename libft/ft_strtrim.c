/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:06:47 by mle-roy           #+#    #+#             */
/*   Updated: 2014/01/27 16:55:11 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	int		endchar;
	int		startchar;

	if (!s)
		return (NULL);
	endchar = 0;
	startchar = 0;
	len = ft_strlen(s);
	while (ft_iswhitespace(s[len - 1 - endchar]))
		endchar++;
	while (ft_iswhitespace(s[startchar]))
		startchar++;
	if ((len - startchar - endchar) <= 0)
		return (ft_strnew(0));
	return (ft_strsub(s, startchar, (size_t) (len - startchar - endchar)));
}
