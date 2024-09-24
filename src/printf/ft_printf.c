/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:06:38 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 18:32:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = ft_vdprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (ret);
}
