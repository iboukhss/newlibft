/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:35:11 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 18:39:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pribuf.h"
#include "libft.h"

int	append_int(t_pribuf *pb, int n)
{
	char	buf[32];

	int_to_str(buf, n, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}

int	append_uint(t_pribuf *pb, unsigned int n)
{
	char	buf[32];

	uint_to_str(buf, n, 10, sizeof(buf) / sizeof(*buf));
	if (append_str(pb, buf) == -1)
		return (-1);
	return (0);
}
