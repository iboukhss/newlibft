/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:07:17 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 19:09:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, ptrdiff_t n)
{
	char		*dp;
	const char	*sp;

	dp = (char *)dst;
	sp = (const char *)src;
	while (n > 0)
	{
		*dp++ = *sp++;
		--n;
	}
	return (dst);
}
