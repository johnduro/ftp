/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:38:05 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:42:15 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_atom_lst_index(t_lst *list, t_atom *atom)
{
	int			i;
	t_atom		*atom_tmp;

	i = 0;
	atom_tmp = list->first;
	while (atom_tmp)
	{
		if (atom_tmp == atom)
			return (i);
		i++;
		atom_tmp = atom_tmp->next;
	}
	return (-1);
}
