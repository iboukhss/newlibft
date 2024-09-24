/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pribuf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:28:41 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 18:29:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIBUF_H
# define PRIBUF_H

# define PRIBUF_SIZE 1024

# include <stddef.h>
# include <stdint.h>

typedef struct s_pribuf
{
	int			fd;
	char		data[PRIBUF_SIZE];
	char		*pos;
	ptrdiff_t	cap;
	ptrdiff_t	written;
}	t_pribuf;

void	pribuf_init(t_pribuf *pb, int fd, ptrdiff_t size);
int		pribuf_flush(t_pribuf *pb);
int		pribuf_append(t_pribuf *pb, const void *src, ptrdiff_t n);

int		append_byte(t_pribuf *pb, int c);
int		append_str(t_pribuf *pb, const char *s);
int		append_int(t_pribuf *pb, int n);
int		append_uint(t_pribuf *pb, unsigned int n);
int		append_ptr(t_pribuf *pb, uintptr_t p);

#endif
