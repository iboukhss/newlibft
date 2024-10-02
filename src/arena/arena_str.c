/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:11:07 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 03:33:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft.h"

char	*arena_strdup(t_arena *a, const char *s)
{
	char		*dup;
	ptrdiff_t	len;

	len = ft_strlen(s);
	dup = arena_alloc(a, (len + 1) * sizeof(*dup));
	ft_memcpy(dup, s, len);
	return (dup);
}

char	*arena_strndup(t_arena *a, const char *s, ptrdiff_t n)
{
	char		*dup;
	ptrdiff_t	len;
	ptrdiff_t	to_copy;

	len = ft_strlen(s);
	if (len > n)
		to_copy = n;
	else
		to_copy = len;
	dup = arena_alloc(a, (to_copy + 1) * sizeof(*dup));
	ft_memcpy(dup, s, to_copy);
	return (dup);
}
