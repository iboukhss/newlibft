/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cirbuf_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:24:48 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 21:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cirbuf.h"

// NOTE: The following function return void pointer which need to be casted
// before being dereferenced, they can also return null pointers which can
// also be very dangerous. Maybe not the best design choice here.

void	*cirbuf_back(t_cirbuf *cbuf)
{
	char		*pos;
	ptrdiff_t	idx;

	if (cirbuf_is_empty(cbuf))
		return (NULL);
	idx = (cbuf->tail - 1 + cbuf->cap) % cbuf->cap;
	pos = (char *)cbuf->data + (idx * cbuf->size);
	return (pos);
}

void	*cirbuf_front(t_cirbuf *cbuf)
{
	char	*pos;

	if (cirbuf_is_empty(cbuf))
		return (NULL);
	pos = (char *)cbuf->data + (cbuf->head * cbuf->size);
	return (pos);
}

// We consider valid circular buffer indices the same as traditional C arrays.
// From 0 to len - 1.
void	*cirbuf_at(t_cirbuf *cbuf, ptrdiff_t idx)
{
	char		*pos;

	if (cirbuf_is_empty(cbuf) || idx < 0 || idx > cbuf->len - 1)
		return (NULL);
	idx = (cbuf->head + idx) % cbuf->cap;
	pos = (char *)cbuf->data + (idx * cbuf->size);
	return (pos);
}

bool	cirbuf_is_empty(t_cirbuf *cbuf)
{
	return (cbuf->len == 0);
}

bool	cirbuf_is_full(t_cirbuf *cbuf)
{
	return (cbuf->len == cbuf->cap);
}
