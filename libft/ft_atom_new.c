/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:05:31 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/21 16:36:02 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_atom		*ft_atom_new(void const *content, size_t size)
{
	t_atom		*new_atom;

	new_atom = (t_atom *)ft_memalloc(sizeof(*new_atom));
	if (new_atom)
	{
		if (content == NULL)
		{
			new_atom->content = NULL;
			new_atom->content_size = 0;
		}
		else
		{
			if ((new_atom->content = ft_memdup(content, size)) == NULL)
			{
				new_atom->content_size = 0;
				return (NULL);
			}
			new_atom->content_size = size;
		}
		new_atom->next = NULL;
		new_atom->prev = NULL;
	}
	return (new_atom);
}
