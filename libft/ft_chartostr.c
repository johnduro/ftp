/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 16:12:23 by mle-roy           #+#    #+#             */
/*   Updated: 2014/01/03 16:27:04 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartostr(char c)
{
	char	*new;

	new = ft_strnew(1);
	if (new == NULL)
		return (NULL);
	*new = c;
	return (new);
}
