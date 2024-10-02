/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:55:40 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 01:27:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "libft.h"

// Growing operations
void	vector_push_back(t_arena *a, void *vecptr, const void *elem)
{
	t_vector	*v;
	char		*pos;

	v = vecptr;
	if (v->end >= v->cap)
		vector_grow(a, vecptr);
	pos = v->data;
	ft_memcpy(pos + (v->end * v->size), elem, v->size);
	v->end += 1;
	v->len += 1;
}

// NOTE: Growing "backwards" seems like a good idea here.
// TODO: Implement `vector_grow_back` and `vector_grow_front`
void	vector_push_front(t_arena *a, void *vecptr, const void *elem)
{
	t_vector	*v;
	char		*pos;

	v = vecptr;
	
}

// Shrinking operations
void	vector_pop_back(void *vecptr)
{
	
}

void	vector_pop_front(void *vecptr)
{
	
}
