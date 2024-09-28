/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:31:43 by iboukhss          #+#    #+#             */
/*   Updated: 2024/09/29 00:53:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>
#include <limits.h>

static bool	is_overflow(int n, int digit)
{
	if (n < 0)
	{
		return (n < (INT_MIN + digit) / 10);
	}
	else
	{
		return (n > (INT_MAX - digit) / 10);
	}
}

// Note: I'm not sure if we should handle whitespaces with this function.
// The assumption here is that str points to some digit or sign in a string.
// If we pass an empty string the function returns EINVAL.
// Leading whitespaces are not handled, as well as any non-digit characters
// past the first one. That means `123abc` is considred a valid integer string
// according to this function.

int	str_to_int(int *out, const char *str)
{
	int	num;
	int	sign;
	int	digit;

	num = 0;
	sign = -1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	if (!ft_isdigit(*str))
		return (EINVAL);
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (is_overflow(num, digit))
			return (EOVERFLOW);
		num *= 10;
		num += sign * digit;
		++str;
	}
	*out = num;
	return (0);
}
