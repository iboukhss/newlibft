/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cirbuf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:38:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 21:19:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRBUF_H
# define CIRBUF_H

# include "arena.h"

# include <stdbool.h>
# include <stddef.h>

typedef struct s_cirbuf
{
	void		*data;
	ptrdiff_t	size;
	ptrdiff_t	head;
	ptrdiff_t	tail;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_cirbuf;

t_cirbuf	*cirbuf_new(t_arena *a, ptrdiff_t nmemb, ptrdiff_t size);
t_cirbuf	*cirbuf_vdup(t_arena *a, void *vecptr);

void		cirbuf_push_back(t_cirbuf *cbuf, const void *elem);
void		cirbuf_push_front(t_cirbuf *cbuf, const void *elem);
void		cirbuf_pop_back(t_cirbuf *cbuf);
void		cirbuf_pop_front(t_cirbuf *cbuf);

bool		cirbuf_is_empty(t_cirbuf *cbuf);
bool		cirbuf_is_full(t_cirbuf *cbuf);

void		*cirbuf_back(t_cirbuf *cbuf);
void		*cirbuf_front(t_cirbuf *cbuf);
void		*cirbuf_at(t_cirbuf *cbuf, ptrdiff_t idx);

void		cirbuf_swap(t_alloc handle, t_cirbuf *cbuf, ptrdiff_t idx_a,
				ptrdiff_t idx_b);

void		cirbuf_shift_left(t_alloc handle, t_cirbuf *cbuf);
void		cirbuf_shift_right(t_alloc handle, t_cirbuf *cbuf);

#endif
