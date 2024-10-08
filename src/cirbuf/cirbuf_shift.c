/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cirbuf_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:18:04 by marvin            #+#    #+#             */
/*   Updated: 2024/10/07 04:25:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cirbuf.h"

#include "libft.h"

// NOTE: Shifting is like removing an element from one extremity and inserting
// it at the opposite extremity.

// An element is allowed to shift itself (arbitrary choice).
void	cirbuf_shift_left(t_alloc handle, t_cirbuf *cbuf)
{
	void	*tmp;

	if (!cirbuf_is_empty(cbuf))
	{
		tmp = arena_alloc(&handle.temp, cbuf->size);
		ft_memcpy(tmp, cirbuf_front(cbuf), cbuf->size);
		cirbuf_pop_front(cbuf);
		cirbuf_push_back(cbuf, tmp);
	}
}

void	cirbuf_shift_right(t_alloc handle, t_cirbuf *cbuf)
{
	void	*tmp;

	if (!cirbuf_is_empty(cbuf))
	{
		tmp = arena_alloc(&handle.temp, cbuf->size);
		ft_memcpy(tmp, cirbuf_back(cbuf), cbuf->size);
		cirbuf_pop_back(cbuf);
		cirbuf_push_front(cbuf, tmp);
	}
}
