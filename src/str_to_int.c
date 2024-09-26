/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:31:43 by iboukhss          #+#    #+#             */
/*   Updated: 2024/09/26 09:57:15 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>
#include <limits.h>

static int	is_overflow(int n, int next_digit)
{
	if (n < 0)
	{
		return (n < (INT_MIN + (next_digit - '0')) / 10);
	}
	else
	{
		return (n > (INT_MAX - (next_digit - '0')) / 10);
	}
}

static int	handle_negative(int *out, const char *s)
{
	*out = 0;
	while (ft_isdigit(*s))
	{
		if (is_overflow(*out, *s))
			return (EOVERFLOW);
		*out = *out * 10 - (*s - '0');
		++s;
	}
	return (0);
}

static int	handle_positive(int *out, const char *s)
{
	*out = 0;
	while (ft_isdigit(*s))
	{
		if (is_overflow(*out, *s))
			return (EOVERFLOW);
		*out = *out * 10 + (*s - '0');
		++s;
	}
	return (0);
}

int	str_to_int(int *out, const char *s)
{
	const char	*sign;
	int			err;

	while (ft_isspace(*s))
		++s;
	sign = s;
	if (*s == '-' || *s == '+')
		++s;
	if (!ft_isdigit(*s))
		return (EINVAL);
	if (*sign == '-')
		err = handle_negative(out, s);
	else
		err = handle_positive(out, s);
	if (err)
		return (err);
	return (0);
}
