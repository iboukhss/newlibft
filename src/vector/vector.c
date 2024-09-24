/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:48:24 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 18:18:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

void	*vector_new(t_arena *a, ptrdiff_t elem_count, ptrdiff_t elem_size)
{
	t_vector	*v;

	v = arena_alloc(a, sizeof(*v));
	v->data = arena_alloc(a, elem_count * elem_size);
	v->size = elem_size;
	v->len = 0;
	v->cap = elem_count;
	return (v);
}

void	*vector_dup(t_arena *a, void *vecptr)
{
	t_vector	*v;
	t_vector	*dup;
	void		*dup_data;

	v = (t_vector *)vecptr;
	dup = arena_alloc(a, sizeof(*dup));
	dup_data = arena_alloc(a, v->len * v->size);
	ft_memcpy(dup_data, v->data, v->len * v->size);
	dup->data = dup_data;
	dup->size = v->size;
	dup->len = v->len;
	dup->cap = v->len;
	return (dup);
}

// Double the size of the vector
void	vector_grow(t_arena *a, void *vecptr)
{
	t_vector	*v;
	void		*new_data;

	v = (t_vector *)vecptr;
	new_data = arena_alloc(a, (v->cap * 2) * v->size);
	ft_memcpy(new_data, v->data, v->len * v->size);
	v->data = new_data;
	v->cap = v->cap * 2;
}

void	vector_push(t_arena *a, void *vecptr, void *elem)
{
	t_vector	*v;
	char		*data;

	v = (t_vector *)vecptr;
	if (v->len >= v->cap)
		vector_grow(a, v);
	data = (char *)v->data;
	ft_memcpy(data + (v->len * v->size), elem, v->size);
	v->len += 1;
}
