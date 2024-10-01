/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:35:11 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 23:28:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pribuf.h"
#include "libft.h"

int	append_int(t_pribuf *pb, int n)
{
	char	buf[FMTBUF_SIZE];

	int_format(buf, n, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}

int	append_uint(t_pribuf *pb, unsigned int n)
{
	char	buf[FMTBUF_SIZE];

	uint_format(buf, n, 10, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}

int	append_pdiff(t_pribuf *pb, ptrdiff_t n)
{
	char	buf[FMTBUF_SIZE];

	int_format(buf, n, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}

int	append_size(t_pribuf *pb, size_t n)
{
	char	buf[FMTBUF_SIZE];

	uint_format(buf, n, 10, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}
