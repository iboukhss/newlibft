/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:48:24 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

// Returns a pointer to a newly allocated vector on the arena.
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

// Initializes a preallocated vector structure.
void	vector_init(t_arena *a, void *vecptr, ptrdiff_t elem_count,
			ptrdiff_t elem_size)
{
	t_vector	*v;

	v = vecptr;
	v->data = arena_alloc(a, elem_count * elem_size);
	v->size = elem_size;
	v->len = 0;
	v->cap = elem_count;
}

// Doubles the capacity of a vector.
// TODO: Think about ways to deal with 0 sized allocations, for now it is
// assumed the initial allocation is greater or equal than 1.
void	vector_grow(t_arena *a, void *vecptr)
{
	t_vector	*v;
	void		*new_data;

	v = vecptr;
	new_data = arena_alloc(a, (v->cap * 2) * v->size);
	ft_memcpy(new_data, v->data, v->len * v->size);
	v->data = new_data;
	v->cap *= 2;
}

// Push an element to a vector.
void	vector_push(t_arena *a, void *vecptr, const void *elem)
{
	t_vector	*v;
	char		*end;

	v = vecptr;
	if (v->len >= v->cap)
		vector_grow(a, v);
	end = (char *)v->data + (v->len * v->size);
	ft_memcpy(end, elem, v->size);
	v->len += 1;
}
