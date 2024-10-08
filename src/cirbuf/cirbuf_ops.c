/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cirbuf_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:39:21 by marvin            #+#    #+#             */
/*   Updated: 2024/10/07 04:30:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cirbuf.h"

#include "libft.h"

// NOTE: A full capacity buffer cannot be overwritten. Pushing to a full
// buffer or popping from an empty buffer is a no-op.

void	cirbuf_push_back(t_cirbuf *cbuf, const void *elem)
{
	void	*pos;

	if (!cirbuf_is_full(cbuf))
	{
		pos = (char *)cbuf->data + (cbuf->tail * cbuf->size);
		ft_memcpy(pos, elem, cbuf->size);
		cbuf->tail = (cbuf->tail + 1) % cbuf->cap;
		cbuf->len += 1;
	}
}

void	cirbuf_push_front(t_cirbuf *cbuf, const void *elem)
{
	void	*pos;

	if (!cirbuf_is_full(cbuf))
	{
		cbuf->head = (cbuf->head - 1 + cbuf->cap) % cbuf->cap;
		pos = (char *)cbuf->data + (cbuf->head * cbuf->size);
		ft_memcpy(pos, elem, cbuf->size);
		cbuf->len += 1;
	}
}

void	cirbuf_pop_back(t_cirbuf *cbuf)
{
	if (!cirbuf_is_empty(cbuf))
	{
		cbuf->tail = (cbuf->tail - 1 + cbuf->cap) % cbuf->cap;
		cbuf->len -= 1;
	}
}

void	cirbuf_pop_front(t_cirbuf *cbuf)
{
	if (!cirbuf_is_empty(cbuf))
	{
		cbuf->head = (cbuf->head + 1) % cbuf->cap;
		cbuf->len -= 1;
	}
}

// Allow an element to swap itself?
void	cirbuf_swap(t_alloc handle, t_cirbuf *cbuf, ptrdiff_t a, ptrdiff_t b)
{
	void	*tmp_a;
	void	*tmp_b;

	if (!cirbuf_is_empty(cbuf) && cirbuf_at(cbuf, a) && cirbuf_at(cbuf, b))
	{
		tmp_a = arena_alloc(&handle.temp, cbuf->size);
		tmp_b = arena_alloc(&handle.temp, cbuf->size);
		ft_memcpy(tmp_a, cirbuf_at(cbuf, a), cbuf->size);
		ft_memcpy(tmp_b, cirbuf_at(cbuf, b), cbuf->size);
		ft_memcpy(cirbuf_at(cbuf, a), tmp_b, cbuf->size);
		ft_memcpy(cirbuf_at(cbuf, b), tmp_a, cbuf->size);
	}
}
