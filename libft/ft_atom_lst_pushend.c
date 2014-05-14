/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_pushend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:20:53 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:23:37 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_atom_lst_pushend(t_lst *list, t_atom *new)
{
	if (list->first == NULL || list->last == NULL)
	{
		list->first = new;
		list->last = new;
		list->len = 1;
	}
	else
	{
		new->prev = list->last;
		list->last->next = new;
		list->last = new;
		list->len++;
	}
}
