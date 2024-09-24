/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:35:55 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 18:39:28 by marvin           ###   ########.fr       */
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

int	append_ptr(t_pribuf *pb, uintptr_t p)
{
	char	buf[32];

	uint_to_str(buf, p, 16, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, "0x") == -1)
		return (-1);
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}
