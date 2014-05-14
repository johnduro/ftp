/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_iter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:53:36 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:55:21 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_atom_lst_iter(t_lst *list, void (*f)(void *content))
{
	t_atom		*atom;

	atom = list->first;
	while (atom)
	{
		f(atom->content);
		atom = atom->next;
	}
}
