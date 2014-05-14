/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:16:47 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:19:38 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_atom_lst_push(t_lst *list, t_atom *new)
{
	if (list->first == NULL || list->last == NULL)
	{
		list->first = new;
		list->last = new;
		list->len = 1;
	}
	else
	{
		list->first->prev = new;
		new->next = list->first;
		list->first = new;
		list->len++;
	}
}
