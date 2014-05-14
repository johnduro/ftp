/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 19:16:24 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/28 22:35:17 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define TINY_M 512
# define SMALL_M 4096

# include <stdlib.h>

typedef struct		s_large
{
	struct s_large	*next;
	struct s_large	*prev;
	size_t			size;
}					t_large;

typedef struct		s_sm
{
	int				tab[100];
	struct s_sm		*next;
}					t_sm;

typedef struct		s_malloc
{
	t_sm			*tiny_m;
	t_sm			*small_m;
	t_large			*large_m;
}					t_malloc;

t_malloc			g_pool;

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
int					is_large(void *ptr);
void				*ft_realloc(void *ptr, size_t size);

#endif
