/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_delatom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:02:02 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 17:06:21 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_atom_lst_delatom(t_lst *l, t_atom *atom, void (*del)(void *content))
{
	if (del != NULL)
		del(atom->content);
	free(atom->content);
	if (atom == l->first)
		ft_atom_lst_pop(l);
	else if (atom == l->last)
		ft_atom_lst_popend(l);
	else
	{
		atom->prev->next = atom->next;
		atom->next->prev = atom->prev;
		l->len--;
	}
	free(atom);
}
