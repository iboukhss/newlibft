/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:44:17 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 13:27:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>
#include <limits.h>

static bool	is_overflow(int num, int digit)
{
	if (num < 0)
	{
		return (num < (INT_MIN + digit) / 10);
	}
	else
	{
		return (num > (INT_MAX - digit) / 10);
	}
}

// Empty strings return EIVNAL.
// Partial integer matches are considered valid as long as the result doesn't
// overflow.
// Leading whitespaces are skipped.
// If a NULL pointer is passed as an `out` argument then the function will
// simply return whether the parsing succeeded or failed.
int	int_parse(int *out, const char *s)
{
	int	num;
	int	sign;
	int	digit;

	num = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		++s;
	if (!ft_isdigit(*s))
		return (EINVAL);
	while (ft_isdigit(*s))
	{
		digit = *s - '0';
		if (is_overflow(num, digit))
			return (EINVAL);
		num = (num * 10) + (sign * digit);
		++s;
	}
	if (out != NULL)
		*out = num;
	return (0);
}
