/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:08:30 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 17:11:12 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_atom_lst_del(t_lst *list, void (*del)(void *content))
{
	t_atom		*atom;
	t_atom		*atom_next;

	atom = list->first;
	while (atom)
	{
		atom_next = atom->next;
		ft_atom_lst_delatom(list, atom, del);
		atom = atom_next;
	}
	free(list);
}
