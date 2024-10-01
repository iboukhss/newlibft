/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:05:32 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 15:06:22 by marvin           ###   ########.fr       */
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

// Function used internally by `ft_printf()` for all unsigned integer types.
// Supports bases up to 16 (arbitrary choice).
int	uint_format(char *buf, uintmax_t val, int base, ptrdiff_t size)
{
	int		len;
	char	*end;

	if (base < 2 || base > 16)
		return (EINVAL);
	len = find_len(val, base);
	if (size < len + 1)
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
