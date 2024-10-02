/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_ndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:19:02 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 22:59:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "arena.h"

// Like `strndup()` but for string arrays.
t_strv	*strv_ndup(t_arena *a, char **strs, ptrdiff_t n)
{
	t_strv		*sv;
	char		*s;
	ptrdiff_t	i;

	i = 0;
	sv = vector_new(a, n, sizeof(char *));
	while (i < n)
	{
		s = arena_strdup(a, strs[i]);
		vector_push(a, sv, &s);
		++i;
	}
	return (sv);
}
