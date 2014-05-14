/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 18:18:32 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/21 16:41:17 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	if ((ret = (t_list *)malloc(sizeof(*ret))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else if ((ret->content = ft_memdup(content, content_size)) == NULL)
	{
		free(ret);
		return (NULL);
	}
	else
		ret->content_size = content_size;
	ret->next = NULL;
	return (ret);
}
