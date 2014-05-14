/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_popend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:33:49 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:37:02 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_atom		*ft_atom_lst_popend(t_lst *list)
{
	t_atom		*pop;

	if (list->first == NULL || list->last == NULL)
		return (NULL);
	pop = list->last;
	if (pop->prev == NULL)
	{
		list->first = NULL;
		list->last = NULL;
	}
	else
	{
		list->last = pop->prev;
		list->last->next = NULL;
	}
	pop->next = NULL;
	pop->prev = NULL;
	list->len--;
	return (pop);
}
