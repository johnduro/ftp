/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 23:15:06 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/28 22:30:32 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static void		*realloc_ts(t_sm *mem, void *ptr, size_t size, size_t m_range)
{
	int		i;

	i = 0;
	while (i < 100)
	{
		if (mem->tab[i] != 0)
		{
			if (((void *)mem + ((i + 1) * m_range)) == ptr)
			{
				if (size <= TINY_M)
				{
					mem->tab[i] = size;
					return (ptr);
				}
				else
				{
					mem->tab[i] = 0;
					return (ft_memcpy(ft_malloc(size), ptr, size));
				}
			}
		}
		i++;
	}
	return (0);
}

static void		*realloc_large(void *ptr, size_t size)
{
	void		*ret;
	t_large		*tmp;

	tmp = g_pool.large_m;
	while (tmp)
	{
		if ((void *)tmp + sizeof(t_large) == ptr)
		{
			ret = ft_malloc(size);
			ret = ft_memcpy(ret, ptr, size);
			ft_free(ptr);
			return (ret);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static void		*search_realloc(void *ptr, size_t size)
{
	void	*ret;
	t_sm	*tmp;

	tmp = g_pool.tiny_m;
	while (tmp)
	{
		if ((ret = realloc_ts(g_pool.tiny_m, ptr, size, TINY_M)))
			return (ret);
		tmp = tmp->next;
	}
	tmp = g_pool.small_m;
	while (tmp)
	{
		if ((ret = realloc_ts(g_pool.small_m, ptr, size, SMALL_M)))
			return (ret);
		tmp = tmp->next;
	}
	if ((ret = realloc_large(ptr, size)))
		return (ret);
	return (NULL);
}

void			*ft_realloc(void *ptr, size_t size)
{
	if (size <= 0)
	{
		ft_free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (ft_malloc(size));
	else
		return (search_realloc(ptr, size));
	return (NULL);
}
