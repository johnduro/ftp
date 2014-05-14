/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 16:46:39 by mle-roy           #+#    #+#             */
/*   Updated: 2013/12/10 18:45:37 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = *alst;
	if (alst == NULL || *alst == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp2;
	}
	*alst = NULL;
}
