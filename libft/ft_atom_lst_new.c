/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 19:02:07 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/21 16:35:03 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst		*ft_atom_lst_new(t_atom *new_atom)
{
	t_lst		*list;

	if ((list = (t_lst *)ft_memalloc(sizeof(*list))) == NULL)
		return (NULL);
	list->len = 0;
	if (new_atom != NULL)
		ft_atom_lst_push(list, new_atom);
	return (list);
}
