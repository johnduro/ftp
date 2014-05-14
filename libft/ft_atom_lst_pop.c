/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_pop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:29:24 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:32:39 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_atom		*ft_atom_lst_pop(t_lst *list)
{
	t_atom		*pop;

	if (list->first == NULL || list->last == NULL)
		return (NULL);
	pop = list->first;
	if (pop->next == NULL)
	{
		list->first = NULL;
		list->last = NULL;
	}
	else
		list->first = pop->next;
	pop->next = NULL;
	pop->prev = NULL;
	list->len--;
	return (pop);
}
