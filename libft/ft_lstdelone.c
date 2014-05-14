/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 17:55:40 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/10 19:19:36 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (alst == NULL || *alst == NULL)
		return ;
	tmp = *alst;
	del(tmp->content, tmp->content_size);
	free(tmp);
	*alst = NULL;
}
