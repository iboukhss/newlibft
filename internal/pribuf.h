/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pribuf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:28:41 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 21:54:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIBUF_H
# define PRIBUF_H

# define PRIBUF_SIZE 1024
# define FMTBUF_SIZE 128

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

int		append_byte(t_pribuf *pb, int c);				// %c
int		append_str(t_pribuf *pb, const char *s);		// %s
int		append_int(t_pribuf *pb, int n);				// %d and %i
int		append_uint(t_pribuf *pb, unsigned int n);		// %u
int		append_hex(t_pribuf *pb, uintmax_t n);			// %p and %x
int		append_oct(t_pribuf *pb, unsigned int n);		// %o
int		append_bin(t_pribuf *pb, unsigned int n);		// %b (new in C23)
int		append_pdiff(t_pribuf *pb, ptrdiff_t n);		// %t (personal ext.)
int		append_size(t_pribuf *pb, size_t n);			// %z (personal ext.)

#endif
