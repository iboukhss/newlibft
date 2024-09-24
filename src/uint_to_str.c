/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:42:32 by marvin            #+#    #+#             */
/*   Updated: 2024/09/22 19:43:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>

static int	find_len(uintmax_t val, int base)
{
	int	len;

	if (val == 0)
		return (1);
	len = 0;
	while (val != 0)
	{
		++len;
		val /= base;
	}
	return (len);
}

int	uint_to_str(char *buf, uintmax_t val, int base, ptrdiff_t bufsize)
{
	int		len;
	char	*end;

	if (base < 2 || base > 16)
		return (EINVAL);
	len = find_len(val, base);
	if (len + 1 > bufsize)
		return (EOVERFLOW);
	end = buf + len;
	*end = '\0';
	while (end > buf)
	{
		*--end = "0123456789abcdef"[val % base];
		val /= base;
	}
	return (0);
}
