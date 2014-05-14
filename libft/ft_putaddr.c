/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 19:07:09 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/28 19:13:22 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	*ft_adresstostr(long unsigned int n)
{
	char	*new;
	char	*tmp;
	int		l;
	char	c;
	char	*table;

	tmp = ft_strdup("00000000000000000000000000000000");
	table = ft_strdup("0123456789abcdefghijklmnopqrstuvwxyz");
	l = 31;
	if (n == 0)
		l--;
	else
	{
		while (n != 0)
		{
			c = table[(n % 16)];
			tmp[l--] = c;
			n = n / 16;
		}
	}
	new = ft_strsub(tmp, (l + 1), ft_strlen(&tmp[l]));
	free(tmp);
	free(table);
	return (new);
}

void	ft_putaddr(long unsigned int addr, int ret)
{
	char	*tmp;
	int		len;

	tmp = ft_adresstostr(addr);
	len = ret - ft_strlen(tmp);
	if (ret <= 0)
	{
		free(tmp);
		return ;
	}
	write(1, "0000000000000000", len);
	write(1, tmp, ft_strlen(tmp));
	write(1, " ", 1);
	free(tmp);
}
