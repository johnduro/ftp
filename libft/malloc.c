/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 23:01:02 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/28 22:26:52 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "ft_malloc.h"
#include "libft.h"

static void		*find_alloc(t_sm *mem, size_t size, int m_range)
{
	int		i;

	i = 0;
	while (i < 100)
	{
		if (mem->tab[i] == 0)
		{
			mem->tab[i] = size;
			return ((void *)mem + ((i + 1) * m_range));
		}
		i++;
	}
	return (NULL);
}

static void		*tiny_malloc(size_t size)
{
	void	*ret;
	t_sm	*bws_tiny;
	t_sm	*keep;

	if (!g_pool.tiny_m)
	{
		g_pool.tiny_m = (t_sm *)mmap(0, 101 * TINY_M, PROT_READ | PROT_WRITE,
									MAP_ANON | MAP_PRIVATE, -1, 0);
		ft_bzero(g_pool.tiny_m->tab, 100 * sizeof(int));
	}
	bws_tiny = g_pool.tiny_m;
	while (bws_tiny)
	{
		if ((ret = find_alloc(bws_tiny, size, TINY_M)))
			return (ret);
		keep = bws_tiny;
		bws_tiny = bws_tiny->next;
	}
	keep->next = (t_sm *)mmap(0, 101 * TINY_M, PROT_READ | PROT_WRITE,
							MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_bzero(keep->next->tab, 100 * sizeof(int));
	return (find_alloc(keep->next, size, TINY_M));
}

static void		*small_malloc(size_t size)
{
	void	*ret;
	t_sm	*bws_small;
	t_sm	*keep;

	if (!g_pool.small_m)
	{
		g_pool.small_m = (t_sm *)mmap(0, 101 * SMALL_M, PROT_READ | PROT_WRITE,
									MAP_ANON | MAP_PRIVATE, -1, 0);
		ft_bzero(g_pool.small_m->tab, 100 * sizeof(int));
	}
	bws_small = g_pool.small_m;
	while (bws_small)
	{
		if ((ret = find_alloc(bws_small, size, SMALL_M)))
			return (ret);
		keep = bws_small;
		bws_small = bws_small->next;
	}
	keep->next = (t_sm *)mmap(0, 101 * SMALL_M, PROT_READ | PROT_WRITE,
							MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_bzero(keep->next->tab, 100 * sizeof(int));
	return (find_alloc(keep->next, size, SMALL_M));
}

static void		*large_malloc(size_t size)
{
	t_large		*bws_large;

	if (!g_pool.large_m)
	{
		g_pool.large_m = (t_large *)mmap(0, size + sizeof(t_large), PROT_READ
						| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g_pool.large_m->next = NULL;
		g_pool.large_m->prev = NULL;
		g_pool.large_m->size = size;
		return ((void *)g_pool.large_m + sizeof(t_large));
	}
	else
	{
		bws_large = g_pool.large_m;
		while (bws_large->next)
			bws_large = bws_large->next;
		bws_large->next = (t_large *)mmap(0, size + sizeof(t_large),
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		bws_large->next->prev = bws_large;
		bws_large = bws_large->next;
		bws_large->next = NULL;
		bws_large->size = size;
		return ((void *)bws_large + sizeof(t_large));
	}
}

void			*ft_malloc(size_t size)
{
	static char		flag = 0;

	if (size <= 0)
		return (NULL);
	if (!flag)
	{
		g_pool.tiny_m = NULL;
		g_pool.small_m = NULL;
		g_pool.large_m = NULL;
		flag = 1;
	}
	if (size <= TINY_M)
		return (tiny_malloc(size));
	else if (size <= SMALL_M)
		return (small_malloc(size));
	else
		return (large_malloc(size));
	return (NULL);
}
