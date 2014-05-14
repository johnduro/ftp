/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 23:12:54 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/28 22:29:26 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "ft_malloc.h"

static void			free_large(t_large *ptr)
{
	if (ptr->prev == NULL && ptr->next == NULL)
		g_pool.large_m = NULL;
	else if (ptr->prev == NULL && ptr->next)
	{
		ptr->next->prev = NULL;
		g_pool.large_m = ptr->next;
	}
	else if (ptr->next == NULL && ptr->prev)
		ptr->prev->next = NULL;
	else if (ptr->prev && ptr->next)
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}
	munmap(ptr, ptr->size + sizeof(t_large));
}

int					is_large(void *ptr)
{
	t_large		*bws_large;

	bws_large = g_pool.large_m;
	while (bws_large)
	{
		if (((void *)bws_large + sizeof(t_large)) == ptr)
		{
			free_large(bws_large);
			return (1);
		}
		bws_large = bws_large->next;
	}
	return (0);
}
