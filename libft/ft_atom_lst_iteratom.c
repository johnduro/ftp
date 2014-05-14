/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_iteratom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:56:42 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:58:32 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_atom_lst_iteratom(t_lst *list, void (*f)(t_atom *atom))
{
	t_atom		*atom;

	atom = list->first;
	while (atom)
	{
		f(atom);
		atom = atom->next;
	}
}
