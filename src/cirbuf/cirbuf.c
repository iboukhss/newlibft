/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cirbuf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:38:17 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 21:34:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cirbuf.h"

#include "libft.h"
#include "vector.h"

t_cirbuf	*cirbuf_new(t_arena *a, ptrdiff_t nmemb, ptrdiff_t size)
{
	t_cirbuf	*new;

	new = arena_alloc(a, sizeof(*new));
	new->data = arena_alloc(a, nmemb * size);
	new->size = size;
	new->head = 0;
	new->tail = 0;
	new->len = 0;
	new->cap = nmemb;
	return (new);
}

// Creates a circular buffer from a vector. Probably not the best name for
// this function.
t_cirbuf	*cirbuf_vdup(t_arena *a, void *vecptr)
{
	t_cirbuf	*new;
	t_vector	*v;

	v = vecptr;
	new = arena_alloc(a, sizeof(*new));
	new->data = arena_alloc(a, v->len * v->size);
	ft_memcpy(new->data, v->data, v->len * v->size);
	new->size = v->size;
	new->head = 0;
	new->tail = 0;
	new->len = v->len;
	new->cap = v->len;
	return (new);
}
