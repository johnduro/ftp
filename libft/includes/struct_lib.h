/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 16:48:29 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/21 16:52:06 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LIB_H
# define STRUCT_LIB_H

typedef struct		s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;

typedef struct		s_atom
{
	void				*content;
	size_t				content_size;
	struct s_atom		*next;
	struct s_atom		*prev;
}					t_atom;

typedef struct		s_lst
{
	t_atom				*first;
	t_atom				*last;
	size_t				len;
}					t_lst;

#endif
