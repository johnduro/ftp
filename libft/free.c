/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 23:10:59 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/28 22:28:25 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int		search_alloc(void *ptr, t_sm *mem, size_t m_range)
{
	int		i;

	i = 0;
	while (i < 100)
	{
		if (mem->tab[i] != 0)
		{
			if (((void *)mem + ((i + 1) * m_range)) == ptr)
			{
				mem->tab[i] = 0;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int		is_tiny(void *ptr)
{
	t_sm	*bws_tiny;

	bws_tiny = g_pool.tiny_m;
	while (bws_tiny)
	{
		if (search_alloc(ptr, bws_tiny, TINY_M))
			return (1);
		bws_tiny = bws_tiny->next;
	}
	return (0);
}

static int		is_small(void *ptr)
{
	t_sm	*bws_small;

	bws_small = g_pool.small_m;
	while (bws_small)
	{
		if (search_alloc(ptr, bws_small, SMALL_M))
			return (1);
		bws_small = bws_small->next;
	}
	return (0);
}

void			ft_free(void *ptr)
{
	if (is_tiny(ptr))
		return ;
	else if (is_small(ptr))
		return ;
	else if (is_large(ptr))
		return ;
	return ;
}
