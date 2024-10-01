/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:07:03 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 15:04:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>

// Get integer length including sign.
static int	intlen(intmax_t val)
{
	int	len;

	if (val == 0)
		return (1);
	len = 0;
	if (val < 0)
		++len;
	while (val != 0)
	{
		++len;
		val /= 10;
	}
	return (len);
}

// This function is used internally by `ft_printf()` to convert all sizes
// of integer types, like ptrdiff_t, int64_t, int32_t ect.
int	int_format(char *buf, intmax_t val, ptrdiff_t size)
{
	intmax_t	oval;
	int			len;
	char		*end;

	oval = val;
	len = intlen(val);
	if (size < len + 1)
		return (EOVERFLOW);
	if (oval > 0)
		val = -val;
	end = buf + len;
	*end = '\0';
	while (end > buf)
	{
		*--end = '0' - (val % 10);
		val /= 10;
	}
	if (oval < 0)
		*buf = '-';
	return (0);
}
