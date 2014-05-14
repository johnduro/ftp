/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atom_lst_cpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:45:19 by mle-roy           #+#    #+#             */
/*   Updated: 2014/02/11 16:51:14 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*ft_atom_lst_cpy(t_lst *lst)
{
	t_lst		*new;
	t_atom		*tmp;

	if ((new = ft_atom_lst_new(NULL)) == NULL)
		return (NULL);
	tmp = lst->first;
	while (tmp)
	{
		ft_atom_lst_pushend(new, ft_atom_new(tmp->content, tmp->content_size));
		tmp = tmp->next;
	}
	return (new);
}
