/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:03:10 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 14:13:52 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_strerror(int errnum)
{
	char		*errmsg[3];

	errmsg[0] = "No error";
	errmsg[1] = "Cannot allocate memory";
	errmsg[2] = "Not found";
	return (errmsg[errnum]);
}

void			ft_exit(char *errmsg, int errnum)
{
	if (errmsg != NULL)
	{
		ft_putstr_fd(errmsg, 2);
		if (errnum > -1)
			ft_putstr_fd(": ", 2);
		else
			ft_putstr_fd("\n", 2);
	}
	if (errnum > -1)
	{
		ft_putstr_fd(ft_strerror(errnum), 2);
		ft_putstr_fd("\n", 2);
	}
	exit(errnum);
}
