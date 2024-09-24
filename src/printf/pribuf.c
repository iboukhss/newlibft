/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pribuf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:16:03 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 18:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pribuf.h"
#include "libft.h"

#include <unistd.h>

void	pribuf_init(t_pribuf *pb, int fd, ptrdiff_t size)
{
	pb->fd = fd;
	pb->pos = pb->data;
	pb->cap = size;
	pb->written = 0;
}

int	pribuf_flush(t_pribuf *pb)
{
	if (write(pb->fd, pb->data, pb->pos - pb->data) == -1)
		return (-1);
	pb->pos = pb->data;
	return (0);
}

int	pribuf_append(t_pribuf *pb, const void *src, ptrdiff_t n)
{
	char		*s;
	ptrdiff_t	space_left;
	ptrdiff_t	to_write;

	s = (char *)src;
	while (n > 0)
	{
		space_left = (pb->data + pb->cap) - pb->pos;
		if (space_left == 0)
		{
			if (pribuf_flush(pb) == -1)
				return (-1);
			space_left = pb->cap;
		}
		if (n < space_left)
			to_write = n;
		else
			to_write = space_left;
		ft_memcpy(pb->pos, s, to_write);
		pb->pos += to_write;
		pb->written += to_write;
		s += to_write;
		n -= to_write;
	}
	return (0);
}
