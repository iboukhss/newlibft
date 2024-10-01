/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:35:55 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 23:29:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pribuf.h"
#include "libft.h"

int	append_byte(t_pribuf *buf, int c)
{
	return (pribuf_append(buf, &c, 1));
}

int	append_str(t_pribuf *pb, const char *str)
{
	ptrdiff_t	len;

	len = ft_strlen(str);
	if (pribuf_append(pb, str, len) == -1)
		return (-1);
	return (0);
}

int	append_bin(t_pribuf *pb, unsigned int n)
{
	char	buf[FMTBUF_SIZE];

	uint_format(buf, n, 2, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, "0b") == -1)
		return (-1);
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}

// uintmax_t because this function deals with both %p and %x modifiers
int	append_hex(t_pribuf *pb, uintmax_t n)
{
	char	buf[FMTBUF_SIZE];

	uint_format(buf, n, 16, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, "0x") == -1)
		return (-1);
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}

int	append_oct(t_pribuf *pb, unsigned int n)
{
	char	buf[FMTBUF_SIZE];

	uint_format(buf, n, 8, sizeof(buf) / sizeof(*buf));
	if (n != 0 && (append_str(pb, "0") == -1))
		return (-1);
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}
