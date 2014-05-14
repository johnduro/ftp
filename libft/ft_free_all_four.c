/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:22:58 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/10 19:19:08 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_all_four(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	if (ptr1 != NULL)
		free(ptr1);
	if (ptr2 != NULL)
		free(ptr2);
	if (ptr3 != NULL)
		free(ptr3);
	if (ptr4 != NULL)
		free(ptr4);
}
