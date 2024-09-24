/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:30:42 by marvin            #+#    #+#             */
/*   Updated: 2024/09/22 19:51:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>

static int	find_len(intmax_t val)
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

int	int_to_str(char *buf, intmax_t val, ptrdiff_t bufsize)
{
	int		len;
	char	*end;

	len = find_len(val);
	if (len + 1 > bufsize)
		return (EOVERFLOW);
	end = buf + len;
	*end = '\0';
	if (val < 0)
		*buf++ = '-';
	else
		val = -val;
	while (end > buf)
	{
		*--end = '0' - (val % 10);
		val /= 10;
	}
	return (0);
}
